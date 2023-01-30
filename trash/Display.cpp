#include "Display.h"
#include <iostream>

Display::Display(int width, int height, const char * title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    //glfwWindowHint(GLFW_RESIZABLE, false);

    this->window = glfwCreateWindow(width, height, title, NULL, NULL);
} // end constructor

Display::~Display()
{
    //glfwDestroyWindow(this->window);
    glfwTerminate();
} // end destructor

void Display::start()
{
    glfwMakeContextCurrent(this->window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glViewport(0, 0, getWidth(), getHeight());

    

    // Render loop
    while(!glfwWindowShouldClose(window))
    {
        //std::cout << glfwGetTime() << std::endl;
        std::cout << getWidth() << " " << getHeight() << std::endl;
        glfwPollEvents();

        // render
        // ------
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(this->window);
    }

    

    delete this;
}

int Display::getWidth()
{
    int result;

    glfwGetWindowSize(this->window, &result, nullptr);
    
    return result;
} // end getWidth

int Display::getHeight()
{
    int result;

    glfwGetWindowSize(this->window, nullptr, &result);

    return result;
} // end getHeight