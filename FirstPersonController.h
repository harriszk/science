/**
 * @file FirstPersonController.h
 * Created on 02/03/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _FIRST_PERSON_CONTROLLER_H_
#define _FIRST_PERSON_CONTROLLER_H_

#include "Controller.h"

class FirstPersonController : public Controller {
    public:
        FirstPersonController(Camera *camera);

        virtual ~FirstPersonController();

        void processKeyboardInput(GLFWwindow *window) override;

        void processMouseMovement(float x, float y) override;

        void processMouseScroll(float dy) override;

        //Camera *camera, 
        void updateCamera(float dt) override;
    private:
        Camera *m_camera;

        float m_lastX;

        float m_lastY;

        bool m_firstMouse;
}; // end FirstPersonController class

#endif