/**
 * @file Controller.h
 * Created on 02/01/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Camera.h"
#include <GLFW/glfw3.h>

class Controller {
    public:
        // Destructor
        virtual ~Controller()
        {

        };

        /**
         * Process input from the user.
         * 
         * @param[in] window Pointer to the GLFW window being used.
         */
        virtual void processInput(GLFWwindow *window) = 0;

        /**
         * Update the camera based on user input/the current state.
         * 
         * @param[in] camera Pointer to the camera object being updated.
         * @param[in] dt The change in time since the last frame.
         */
        //Camera *camera, 
        virtual void updateCamera(float dt) = 0;
    protected:
        // Flag to indicate to move the camera forward
        bool m_forward = false;

        // Flag to indicate to move the camera backward
        bool m_backward = false;

        // Flag to indicate to move the camera left
        bool m_left = false;

        // Flag to indicate to move the camera right
        bool m_right = false;
}; // end Controller class

#endif