// @file camera_2d.h
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _CAMERA_2D_H_
#define _CAMERA_2D_H_

#include "Camera.h"

class Camera2D : public Camera {
  public:
    // Constructor.
    Camera2D();

    // Destructor.
    virtual ~Camera2D();

    glm::vec3 get_position() const override;

    glm::mat4 get_view_matrix() const override;

    glm::mat4 get_projection_matrix() const override;

    void Update() override;

    void ProcessKeyboard(Movement direction, float dt) override;

    void ProcessMouseMovement(float dx, float dy) override;

    void ProcessMouseScroll(float dy) override;
};

#endif