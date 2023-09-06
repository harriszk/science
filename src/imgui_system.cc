// @file imgui_system.cc
// Created on 08/14/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "imgui_system.h"

#include <GLFW/glfw3.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "events/window_resized_event.h"
#include "events/mouse_button_pressed_event.h"
#include "events/mouse_button_released_event.h"
#include "events/mouse_moved_event.h"
#include "events/mouse_scrolled_event.h"
#include "events/key_pressed_event.h"
#include "events/key_released_event.h"
#include "events/key_typed_event.h"
#include "event_manager.h"

#include "logger.h"

ImGuiSystem::ImGuiSystem() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO& io = ImGui::GetIO(); 
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  io.KeyMap[ImGuiKey_Backspace] = KeyCode::BACKSPACE;
  io.KeyMap[ImGuiKey_LeftArrow] = KeyCode::KEY_LEFT;
  io.KeyMap[ImGuiKey_RightArrow] = KeyCode::KEY_RIGHT;
  io.KeyMap[ImGuiKey_UpArrow] = KeyCode::KEY_UP;
  io.KeyMap[ImGuiKey_DownArrow] = KeyCode::KEY_DOWN;
  io.KeyMap[ImGuiKey_PageUp] = KeyCode::PAGE_UP;
  io.KeyMap[ImGuiKey_PageDown] = KeyCode::PAGE_DOWN;
  io.KeyMap[ImGuiKey_Home] = KeyCode::HOME;
  io.KeyMap[ImGuiKey_End] = KeyCode::END;
  io.KeyMap[ImGuiKey_Insert] = KeyCode::INSERT;
  io.KeyMap[ImGuiKey_Delete] = KeyCode::DELETE;
  io.KeyMap[ImGuiKey_Enter] = KeyCode::ENTER;
  io.KeyMap[ImGuiKey_Escape] = KeyCode::ESCAPE;
  io.KeyMap[ImGuiKey_Tab] = KeyCode::TAB;
  io.KeyMap[ImGuiKey_LeftSuper] = KeyCode::LEFT_SUPER;
  io.KeyMap[ImGuiKey_RightSuper] = KeyCode::RIGHT_SUPER;
  io.KeyMap[ImGuiKey_Space] = KeyCode::SPACE;
  io.KeyMap[ImGuiKey_A] = KeyCode::A;
  io.KeyMap[ImGuiKey_C] = KeyCode::C;
  io.KeyMap[ImGuiKey_V] = KeyCode::V;
  io.KeyMap[ImGuiKey_X] = KeyCode::X;

  io.DisplaySize = ImVec2(0.0f, 0.0f);
  io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

  //ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  EventManager* manager = EventManager::Get();
  manager->Subscribe(this, EventType::WindowResized);
  manager->Subscribe(this, EventType::WindowMoved);
  manager->Subscribe(this, EventType::MouseButtonPressed);
  manager->Subscribe(this, EventType::MouseButtonReleased);
  manager->Subscribe(this, EventType::MouseMoved);
  manager->Subscribe(this, EventType::MouseScrolled);
  manager->Subscribe(this, EventType::KeyPressed);
  manager->Subscribe(this, EventType::KeyReleased);
  manager->Subscribe(this, EventType::KeyTyped);
}

ImGuiSystem::~ImGuiSystem() {
  for (Panel* panel : panels_) {
    delete panel;
  }

  ImGui_ImplOpenGL3_Shutdown();
  //ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void ImGuiSystem::AddPanel(Panel* panel) {
  panels_.push_back(panel);
}

void ImGuiSystem::OnUpdate() {
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  float time = (float)glfwGetTime();
  io.DeltaTime = time - time_;
  time_ = time;

  ImGui_ImplOpenGL3_NewFrame();
  //ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

  for(Panel* panel : panels_) {
    panel->Render();
  }

  // TEMP: These panels should be put into their own file
  // and then we render them from a list of panels that can be 
  // changed depending on what interface we want to use.
  /*
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
  */
  // TEMP: End

  static bool show = true;
  ImGui::ShowDemoWindow(&show);

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  //ImGui::UpdatePlatformWindows();
  //ImGui::RenderPlatformWindowsDefault();
}

void ImGuiSystem::OnEvent(const Event& event) {
  switch (event.get_event_category()) {
    case EventCategory::Mouse:
      OnMouseEvent(event);
      break;
    case EventCategory::Keyboard:
      OnKeyboardEvent(event);
      break;
    case EventCategory::Window:
      if (event.get_event_type() == EventType::WindowResized) {
        const WindowResizedEvent& window_event = static_cast<const WindowResizedEvent&>(event);

        float x_ratio = window_event.get_monitor_width() / window_event.get_width();
        float y_ratio = window_event.get_monitor_height() / window_event.get_height();

        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(window_event.get_width(), window_event.get_height());
        io.DisplayFramebufferScale = ImVec2(x_ratio, y_ratio);
      }
      break;
    default:
      break;
  }
}

void ImGuiSystem::OnMouseEvent(const Event& event) {
  switch (event.get_event_type()) {
    case EventType::MouseButtonPressed: {
      const MouseButtonPressedEvent& mouse_event = static_cast<const MouseButtonPressedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.MouseDown[mouse_event.get_button()] = true;

      break;
    }
    case EventType::MouseButtonReleased: {
      const MouseButtonReleasedEvent& mouse_event = static_cast<const MouseButtonReleasedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.MouseDown[mouse_event.get_button()] = false;

      break;
    }
    case EventType::MouseMoved: {
      const MouseMovedEvent& mouse_event = static_cast<const MouseMovedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.MousePos = ImVec2(mouse_event.get_x(), mouse_event.get_y());

      break;
    }
    case EventType::MouseScrolled: {
      const MouseScrolledEvent& mouse_event = static_cast<const MouseScrolledEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.MouseWheel += mouse_event.get_dy();

      break;
    }
    default:
      break;
  }
}

void ImGuiSystem::OnKeyboardEvent(const Event& event) {
  switch (event.get_event_type()) {
    case EventType::KeyPressed: {
      const KeyPressedEvent& key_event = static_cast<const KeyPressedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.KeysDown[key_event.get_key_code()] = true;

      io.KeyCtrl = io.KeysDown[KeyCode::LEFT_CONTROL] || io.KeysDown[KeyCode::RIGHT_CONTROL];
      io.KeyShift = io.KeysDown[KeyCode::LEFT_SHIFT] || io.KeysDown[KeyCode::RIGHT_SHIFT];
      io.KeyAlt = io.KeysDown[KeyCode::LEFT_ALT] || io.KeysDown[KeyCode::RIGHT_ALT];
      io.KeySuper = io.KeysDown[KeyCode::LEFT_SUPER] || io.KeysDown[KeyCode::RIGHT_SUPER];
      break;
    }
    case EventType::KeyReleased: {
      const KeyPressedEvent& key_event = static_cast<const KeyPressedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.KeysDown[key_event.get_key_code()] = false;

      break;
    }
    case EventType::KeyTyped: {
      const KeyTypedEvent& key_event = static_cast<const KeyTypedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      
      int key_code = key_event.get_key_code();
      if (key_code > 0 && key_code < 0x10000) {
        io.AddInputCharacter((unsigned short)key_code);
      }

      break;
    }
    default:
      break;
  }
}