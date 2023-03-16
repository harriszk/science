/**
 * @file Controller2D.h
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _CONTROLLER_2D_H_
#define _CONTROLLER_2D_H_

#include "Controller.h"

class Controller2D : public Controller {
    public:
        Controller2D(Camera *camera);

        virtual ~Controller2D();

        void processKeyboardInput(GLFWwindow *window) override;

        void processMouseMovement(float x, float y) override;

        void processMouseScroll(float dy) override;
 
        void updateCamera(float dt) override;
    
    private:
        Camera *m_camera;
}; // end Contorller2D class

#endif