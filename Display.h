/**
 * @file Display.h
 * Created on 01/16/2023
 * 
 * This class creates and manages a GLFW window.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Display {
    public:
        /**
         * Default constructor.
         * 
         * @param[in] width     The width of the window
         * @param[in] height    The height of the window
         * @param[in] title     The title of the window
         */
        Display(int width, int height, const char *title);

        // Destructor
        ~Display();

        /**
         * Creates the GLFW window and initializes GLAD.
         * 
         */
        void createWindow();

        /**
         * Checks if the window should be closed.
         * 
         * @return true         The window should be closed
         * @return false        The window should not be closed
         */
        bool shouldClose();

        /**
         * Toggles the visibility of the window.
         * 
         */
        void toggleWindow();

        /**
         * Updates the window by processing pending events
         * and swapping buffers.
         * 
         */
        void update();

        /**
         * Destroys the window and cleans up GLFW and GLAD.
         * ** Maybe this should just be the destructor? **
         */
        void destroy();

        /**
         * Sets the title of the window.
         * 
         * @param[in] title     The title of the window
         */
        void setTitle(const char *title);
    private:
        // Pointer to the GLFW window.
        GLFWwindow *m_window;

        // Boolean indicating if the window is open or not.
        bool m_isOpen;
}; // end Display class

#endif