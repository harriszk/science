// @file controller.h
// Created on 02/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include <GLFW/glfw3.h>

#include "camera.h"

class Controller {
  public:
    // Destructor.
    virtual ~Controller() {};

    // Process input from the user.
    // 
    // @param[in] window Pointer to the GLFW window being used.
    virtual void ProcessKeyboardInput(GLFWwindow* window) = 0;

    // 
    // 
    // @param[in] x 
    // @param[in] y 
    virtual void ProcessMouseMovement(float x, float y) = 0;

    // 
    // 
    // @param[in] dy 
    virtual void ProcessMouseScroll(float dy) = 0;

    // 
    // 
    // @param[in] dt 
    virtual void UpdateCamera(float dt) = 0;

  protected:
    // Flag to indicate to move the camera forward.
    bool forward_ = false;

    // Flag to indicate to move the camera backward.
    bool backward_ = false;

    // Flag to indicate to move the camera left.
    bool left_ = false;

    // Flag to indicate to move the camera right.
    bool right_ = false;

    // Flag to indicate to move the camera up.
    bool up_ = false;

    // Flag to indicate to move the camera down.
    bool down_ = false;
};

#endif