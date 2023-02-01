/**
 * @file Display.cpp
 * Created on 01/30/2023
 * 
 * Implementation of the Display class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Display.h"


Display::Display(int width, int height, const char *title)
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
} // end destructor

void Display::screenSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout << "Display has been resized to (" << width << "x" << height << ")\n";
} // end screenSizeCallback

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
    //glfwSetFramebufferSizeCallback(m_window, screenSizeCallback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    } // end if

    return true;
} // end createWindow

bool Display::shouldClose()
{
    return glfwWindowShouldClose(m_window);
} // end shouldClose

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