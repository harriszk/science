#include "Display.h"
#include <GLFW/glfw3.h>
#include <iostream>

Display::Display(int width, int height):
    width(width),
    height(height)
{
    GLFWwindow* window;

    // Initialize the library 
    if (!glfwInit())
        return;

    // Create a windowed mode window and its OpenGL context 
    window = glfwCreateWindow(this->width, this->height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return;
    }
    
    // Loop until the user closes the window 
    while (!glfwWindowShouldClose(window))
    {
        // Render here 
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap front and back buffers 
        glfwSwapBuffers(window);

        // Poll for and process events 
        glfwPollEvents();
    }

    glfwTerminate();

} // end constructor

Display::~Display()
{
    glfwTerminate();
} // end destructor