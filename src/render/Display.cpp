/**
 * @file Display.cpp
 * Created on 01/30/2023
 * 
 * Implementation of the Display class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/render/Display.h"
#include <cmath>

#include "../../include/render/third-parties/include/imgui/imgui.h"
#include "../../include/render/third-parties/include/imgui/imgui_impl_glfw.h"
#include "../../include/render/third-parties/include/imgui/imgui_impl_opengl3.h"
#include <stdio.h>

Display::Display(int width, int height, const char *title):
    m_renderer(nullptr),
    m_controller(nullptr),
    m_dt(0.0f),
    m_lastFrame(0.0f),
    m_xpos(0.0f),
    m_ypos(0.0f)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    if(!createWindow(width, height, title))
    {
        std::cout << "Window was not created!\n";
        return;
    } // end if

    m_isOpen = true;


    glGenFramebuffers(1, &m_FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

    glGenTextures(1, &m_texture_id);
    glBindTexture(GL_TEXTURE_2D, m_texture_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture_id, 0);

    glGenRenderbuffers(1, &m_RBO);
    glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
      std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!\n";

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindRenderbuffer(GL_RENDERBUFFER, 0);



    // Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; 
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    // Initialize ImGui backend for GLFW and OpenGL
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
} // end default constructor

Display::~Display()
{
    destroy();
    m_window = nullptr;
    
    //delete m_controller;
    m_controller = nullptr;
} // end destructor

bool Display::createWindow(int width, int height, const char *title)
{
    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if(m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    } // end if

    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, screenSizeCallback);

    //glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    } // end if

    return true;
} // end createWindow

void Display::start()
{
    if(!m_renderer)
    {
        std::cout << "ERROR::DISPLAY::RENDERER: No renderer associated with display!" << std::endl;
        return;
    } // end if

    glEnable(GL_DEPTH_TEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    while(!glfwWindowShouldClose(m_window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        m_dt = currentFrame - m_lastFrame;
        m_lastFrame = currentFrame;

        processInput();

        update();
    } // end while
} // end start

void Display::paintFrame()
{
    m_renderer->setWidth(getWidth());
    m_renderer->setHeight(getHeight());

    if(m_isOpen)
    {
        // Start a new ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

        if(ImGui::BeginMainMenuBar()) {
          if(ImGui::BeginMenu("File")) {
            ImGui::EndMenu();
          }

          if(ImGui::BeginMenu("Edit")) {
            ImGui::EndMenu();
          }

          ImGui::EndMainMenuBar();
        }

        ImGui::Begin("Elements");
        ImGui::End();

        ImGui::Begin("Console");
        ImGui::End();

        ImGui::Begin("Log");
        ImGui::End();

        

        //ImGui::ShowDemoWindow();
        // ImGui UI logic and rendering goes here
        ImGui::Begin("Scene");
        // Add ImGui components for your simulation controls, dropdown menus, etc.

        const float window_width = ImGui::GetContentRegionAvail().x;
		    const float window_height = ImGui::GetContentRegionAvail().y;

        ImVec2 pos = ImGui::GetCursorScreenPos();
        
        ImGui::GetWindowDrawList()->AddImage(
          (void *)m_texture_id, 
          ImVec2(pos.x, pos.y), 
          ImVec2(pos.x + window_width, pos.y + window_height), 
          ImVec2(0, 1), 
          ImVec2(1, 0)
        );




        ImGui::End();


        // Render ImGui
        ImGui::Render();

        float currentFrame = static_cast<float>(glfwGetTime());
        m_dt = currentFrame - m_lastFrame;
        m_lastFrame = currentFrame;

        glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

        processInput();
        m_renderer->render();

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

        update();
    } // end if
} // end paintFrame

bool Display::shouldClose()
{
    return glfwWindowShouldClose(m_window);
} // end shouldColse

void Display::toggleWindow()
{
    if(m_isOpen) {
        glfwHideWindow(m_window);
        m_isOpen = false;
    } else {
        glfwShowWindow(m_window);
        m_isOpen = true;
    } // end if
} // end toggleWindow

void Display::update()
{
    glfwSwapBuffers(m_window);
    glfwPollEvents();
} // end update

void Display::destroy()
{
    // Shutdown ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glDeleteFramebuffers(1, &m_FBO);
    glDeleteTextures(1, &m_texture_id);
    glDeleteRenderbuffers(1, &m_RBO);

    glfwDestroyWindow(m_window);
    glfwTerminate();
} // end destroy

void Display::setTitle(const char *title)
{
    glfwSetWindowTitle(m_window, title);
} // end setTitle

void Display::setRenderer(Renderer *renderer)
{
    m_renderer = renderer;
} // end setRenderer

void Display::setContorller(Controller *controller)
{
    m_controller = controller;
} // end setController

int Display::getWidth()
{
    int width;
    glfwGetWindowSize(m_window, &width, nullptr);

    return width;
} // end getWidth

int Display::getHeight()
{
    int height;
    glfwGetWindowSize(m_window, nullptr, &height);
    
    return height;
} // end getHeight

void Display::processInput()
{
    if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(m_window, true);
        /*
        if(m_mouseHidden) {
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        } else {
            glfwSetInputMode(m_window, GLFW_CURSOR, );
        } // end if
        */
    } // end if

    if(glfwGetKey(m_window, GLFW_KEY_1) == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } // if

    if(glfwGetKey(m_window, GLFW_KEY_2) == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    } // end if

    if(!m_controller)
    {
        std::cout << "ERROR::DISPLAY::CONTROLLER: No controller associated with display!" << std::endl;
        return;
    } // end if

    m_controller->processKeyboardInput(m_window);

    glfwGetCursorPos(m_window, &m_xpos, &m_ypos);

    m_xpos = fmod(m_xpos, 3600.0);

    //std::cout << "x: " << m_xpos << " - y: " << m_ypos << std::endl;

    m_controller->processMouseMovement(m_xpos, m_ypos);
    m_controller->updateCamera(m_dt);
} // end processInput

void Display::screenSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    //std::cout << "Display has been resized to (" << width << "x" << height << ")\n";
} // end screenSizeCallback