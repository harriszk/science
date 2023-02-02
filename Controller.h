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

#include <GLFW/glfw3.h>

class Controller {
    public:
        Controller();

        ~Controller();

        void handleInput(GLFWwindow *window, float dt);


    private:

}; // end Controller class

#endif