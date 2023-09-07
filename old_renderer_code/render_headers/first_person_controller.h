// @file first_person_controller.h
// Created on 02/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _FIRST_PERSON_CONTROLLER_H_
#define _FIRST_PERSON_CONTROLLER_H_

#include "controller.h"

class FirstPersonController : public Controller {
  public:
    // Default constructor.
    // 
    // @param[in] camera 
    FirstPersonController(Camera* camera);

    // Destructor.
    virtual ~FirstPersonController();

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

    // 
    float previous_x_;

    // 
    float previous_y_;

    // 
    bool first_mouse_;
};

#endif