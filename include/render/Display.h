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
#include <iostream>
#include "Controller.h"
#include "Renderer.h"

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
         * @param[in] width     The width of the window
         * @param[in] height    The height of the window
         * @param[in] title     The title of the window
         * 
         * @return true     The window was successfully created.
         * @return false    The window wasn't successfully created.
         */
        bool createWindow(int width, int height, const char *title);

        /**
         * 
         * 
         */
        void start();

        /**
         * 
         * 
         */
        void paintFrame();

        /**
         * 
         * 
         * @return true 
         * @return false 
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

        /**
         * 
         * 
         * @param[in] renderer 
         */
        void setRenderer(Renderer *renderer);

        /**
         * 
         * 
         * @param[in] controller 
         */
        void setContorller(Controller *controller);
        
        /**
         * 
         * 
         * @return int 
         */
        int getWidth();

        /**
         * Get the Height object
         * 
         * @return int 
         */
        int getHeight();

        /**
         * 
         * 
         */
        void processInput();

        /**
         * 
         * 
         * @param[in] window 
         * @param[in] width 
         * @param[in] height 
         */
        static void screenSizeCallback(GLFWwindow* window, int width, int height);
    private:
        // Pointer to the GLFW window.
        GLFWwindow *m_window;

        // 
        Renderer *m_renderer;

        // 
        Controller *m_controller;

        // Boolean indicating if the window is open or not.
        bool m_isOpen;

        // The change in time since the last frame.
        float m_dt;

        // Time since the last frame
        float m_lastFrame;

        // The verical position of the cursor.
        double m_xpos;

        // The horizontal position of the cursor.
        double m_ypos;


        GLuint m_FBO;
        GLuint m_RBO;
        GLuint m_texture_id;
}; // end Display class

#endif