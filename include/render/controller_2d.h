// @file controller_2d.h
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _CONTROLLER_2D_H_
#define _CONTROLLER_2D_H_

#include "controller.h"

class Controller2D : public Controller {
  public:
    // Default constructor.
    // 
    // @param[in] camera 
    Controller2D(Camera* camera);

    // Destructor.
    // 
    virtual ~Controller2D();

    // 
    // 
    // @param[in] window 
    void ProcessKeyboardInput(GLFWwindow* window) override;

    // 
    // 
    // @param[in] x 
    // @param[in] y 
    void ProcessMouseMovement(float x, float y) override;

    // 
    // 
    // @param[in] dy 
    void ProcessMouseScroll(float dy) override;

    // 
    // 
    // @param[in] dt 
    void UpdateCamera(float dt) override;

  private:
    // 
    Camera* camera_;
};

#endif