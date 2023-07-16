// @file display.cc
// Created on 01/30/2023
// 
// Implementation of the Display class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/display.h"

#include <stdio.h>

#include <cmath>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

Display::Display(int width, int height, const char* title)
    : renderer_(nullptr),
      controller_(nullptr),
      dt_(0.0f),
      last_frame_(0.0f),
      x_pos_(0.0f),
      y_pos_(0.0f) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  if (!CreateWindow(width, height, title)) {
    std::cout << "Window was not created!\n";
    return;
  }

  is_open_ = true;

  glGenFramebuffers(1, &fbo_);
  glBindFramebuffer(GL_FRAMEBUFFER, fbo_);

  glGenTextures(1, &texture_id_);
  glBindTexture(GL_TEXTURE_2D, texture_id_);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_id_, 0);

  glGenRenderbuffers(1, &rbo_);
  glBindRenderbuffer(GL_RENDERBUFFER, rbo_);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo_);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
    std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!\n";
  }

  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glBindTexture(GL_TEXTURE_2D, 0);
  glBindRenderbuffer(GL_RENDERBUFFER, 0);

  glBindFramebuffer(GL_FRAMEBUFFER, 0);



  // Initialize ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; 
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  // Initialize ImGui backend for GLFW and OpenGL
  ImGui_ImplGlfw_InitForOpenGL(window_, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  glEnable(GL_DEPTH_TEST);  
} // end default constructor

Display::~Display() {
  Destroy();
  window_ = nullptr;
  
  //delete controller_;
  controller_ = nullptr;
}

bool Display::CreateWindow(int width, int height, const char* title) {
  window_ = glfwCreateWindow(width, height, title, NULL, NULL);
  if (window_ == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window_);
  glfwSetFramebufferSizeCallback(window_, ScreenSizeCallback);

  //glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return false;
  }

  return true;
}

void Display::Start() {
  if (!renderer_) {
    std::cout << "ERROR::DISPLAY::RENDERER: No renderer associated with the display!\n";
    return;
  }

  glEnable(GL_DEPTH_TEST);
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  while (!glfwWindowShouldClose(window_)) {
    float currentFrame = static_cast<float>(glfwGetTime());
    dt_ = currentFrame - last_frame_;
    last_frame_ = currentFrame;

    ProcessInput();

    Update();
  }
}

void Display::PaintFrame() {
  renderer_->set_width(get_width());
  renderer_->set_height(get_height());

  if (is_open_) {
    // Start a new ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

    if (ImGui::BeginMainMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        ImGui::EndMenu();
      }

      if (ImGui::BeginMenu("Edit")) {
        ImGui::EndMenu();
      }

      ImGui::EndMainMenuBar();
    }

    //ImGui::ShowDebugLogWindow();

    ImGui::Begin("Elements Tree");
    ImGui::End();

    ImGui::Begin("Properties");
    ImGui::End();

    ImGui::Begin("Console");
    ImGui::End();

    ImGui::Begin("Log");

    // Display mouse position
    const ImVec2& mouse_delta = ImGui::GetIO().MouseDelta;

    if (mouse_delta.x != 0 || mouse_delta.y != 0) {
      // Create a buffer to store the formatted message
      char buffer[100]; // Adjust the buffer size as needed

      // Use sprintf to format the message and store it in the buffer
      std::sprintf(buffer, "[io] Mouse captured: (%.4f, %.4f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);

      // Convert the buffer to a std::string if needed
      std::string message(buffer);
      event_log_.push_back(message);
    }

    ImGui::BeginChild("##log", ImVec2(0.0f, 0.0f), true, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_AlwaysHorizontalScrollbar);

    for (const auto& event : event_log_) {
        ImGui::TextUnformatted(event.c_str());
    }

    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) {
        ImGui::SetScrollHereY(1.0f);
    }

    ImGui::EndChild();

    /*
    ImGui::Text("Mouse Position: (%.1f, %.1f)", ImGui::GetIO().MousePos.x, ImGui::GetIO().MousePos.y);

    // Display mouse button states
    ImGui::Text("Mouse Buttons:");
    ImGui::Text("Left: %s", ImGui::GetIO().MouseDown[0] ? "Down" : "Up");
    ImGui::Text("Right: %s", ImGui::GetIO().MouseDown[1] ? "Down" : "Up");
    ImGui::Text("Middle: %s", ImGui::GetIO().MouseDown[2] ? "Down" : "Up");

    ImGui::GetIO().

    // Display keyboard key states (you can add more keys as needed)
    ImGui::Text("Keyboard Keys:");
    ImGui::Text("A: %s", ImGui::GetIO().KeysDown[ImGuiKey_A] ? "Down" : "Up");
    ImGui::Text("B: %s", ImGui::GetIO().KeysDown[ImGuiKey_B] ? "Down" : "Up");
    ImGui::Text("C: %s", ImGui::GetIO().KeysDown[ImGuiKey_C] ? "Down" : "Up");
    // Add more key states as needed
    */

    ImGui::End();

    ImGui::Begin("Project");
    ImGui::End();

    

    //ImGui::ShowDemoWindow();
    // ImGui UI logic and rendering goes here
    ImGui::Begin("Scene");
    // Add ImGui components for your simulation controls, dropdown menus, etc.

    const float window_width = ImGui::GetContentRegionAvail().x;
    const float window_height = ImGui::GetContentRegionAvail().y;

    ImVec2 pos = ImGui::GetCursorScreenPos();
    
    ImGui::GetWindowDrawList()->AddImage(
      (void *)texture_id_, 
      ImVec2(pos.x, pos.y), 
      ImVec2(pos.x + window_width, pos.y + window_height), 
      ImVec2(0, 1), 
      ImVec2(1, 0)
    );




    ImGui::End();


    // Render ImGui
    ImGui::Render();

    float currentFrame = static_cast<float>(glfwGetTime());
    dt_ = currentFrame - last_frame_;
    last_frame_ = currentFrame;

    glBindFramebuffer(GL_FRAMEBUFFER, fbo_);

    ProcessInput();
    renderer_->Render();

    glBindFramebuffer(GL_FRAMEBUFFER, 0);


    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
      GLFWwindow* backup_current_context = glfwGetCurrentContext();
      ImGui::UpdatePlatformWindows();
      ImGui::RenderPlatformWindowsDefault();
      glfwMakeContextCurrent(backup_current_context);
    }

    Update();
  }
}

bool Display::ShouldClose() {
  return glfwWindowShouldClose(window_);
}

void Display::ToggleWindow() {
  if (is_open_) {
    glfwHideWindow(window_);
    is_open_ = false;
  } else {
    glfwShowWindow(window_);
    is_open_ = true;
  }
}

void Display::Update() {
  glfwSwapBuffers(window_);
  glfwPollEvents();
}

void Display::Destroy() {
  // Shutdown ImGui
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glDeleteFramebuffers(1, &fbo_);
  glDeleteTextures(1, &texture_id_);
  glDeleteRenderbuffers(1, &rbo_);

  glfwDestroyWindow(window_);
  glfwTerminate();
}

void Display::set_title(const char* title) {
  glfwSetWindowTitle(window_, title);
}

void Display::set_renderer(Renderer* renderer) {
  renderer_ = renderer;
}

void Display::set_controller(Controller* controller) {
  controller_ = controller;
}

int Display::get_width() {
  int width;
  glfwGetWindowSize(window_, &width, nullptr);

  return width;
}

int Display::get_height() {
  int height;
  glfwGetWindowSize(window_, nullptr, &height);
  
  return height;
}

void Display::ProcessInput() {
  if (glfwGetKey(window_, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
    glfwSetWindowShouldClose(window_, true);
    /*
    if (mouse_hidden_) {
      glfwSetInputMode(window_, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    } else {
      glfwSetInputMode(window_, GLFW_CURSOR, );
    }
    */
  }

  if (glfwGetKey(window_, GLFW_KEY_1) == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  }

  if (glfwGetKey(window_, GLFW_KEY_2) == GLFW_PRESS) {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  }

  if (!controller_) {
    std::cout << "ERROR::DISPLAY::CONTROLLER: No controller associated with display!" << std::endl;
    return;
  }

  controller_->ProcessKeyboardInput(window_);

  glfwGetCursorPos(window_, &x_pos_, &y_pos_);

  x_pos_ = fmod(x_pos_, 3600.0);

  //std::cout << "x: " << x_pos_ << " - y: " << y_pos_ << std::endl;

  controller_->ProcessMouseMovement(x_pos_, y_pos_);
  controller_->UpdateCamera(dt_);
}

void Display::ScreenSizeCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
  //std::cout << "Display has been resized to (" << width << "x" << height << ")\n";
}