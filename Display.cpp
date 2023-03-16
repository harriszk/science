/**
 * @file Display.cpp
 * Created on 01/30/2023
 * 
 * Implementation of the Display class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Display.h"
#include <cmath>

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

        m_renderer->render();

        update();
    } // end while
} // end start

void Display::paintFrame()
{
    float currentFrame = static_cast<float>(glfwGetTime());
    m_dt = currentFrame - m_lastFrame;
    m_lastFrame = currentFrame;

    processInput();

    m_renderer->render();

    update();
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
    }

    if(glfwGetKey(m_window, GLFW_KEY_2) == GLFW_PRESS)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

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

/*
// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = glm::normalize(front);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    fov -= (float)yoffset;
    if (fov < 1.0f)
        fov = 1.0f;
    if (fov > 45.0f)
        fov = 45.0f;
}
*/