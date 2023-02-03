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
        FirstPersonController();

        virtual ~FirstPersonController();

        void processInput(GLFWwindow *window) override;

        //Camera *camera, 
        void updateCamera(float dt) override;
    private:
}; // end FirstPersonController class

#endif