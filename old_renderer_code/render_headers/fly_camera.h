// @file fly_camera.h
// Created on 02/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _FLY_CAMERA_H_
#define _FLY_CAMERA_H_

#include "camera.h"

class FlyCamera : public Camera {
  public:
    // Default onstructor.
    // 
    // @param[in] position The initial position of the camera.
    // @param[in] direction The initial direction the camera is facing.
    FlyCamera(const glm::vec3& position, const glm::vec3& direction);

    // Destructor.
    virtual ~FlyCamera();

    // Get the position
    // 
    // @return glm::vec3 
    glm::vec3 get_position() const override;

    // Get the view matrix
    // 
    // @return glm::mat4 
    glm::mat4 get_view_matrix() const override;

    // Get the projection matrix
    // 
    // @return glm::mat4 
    glm::mat4 get_projection_matrix() const override;

    // 
    // 
    void Update() override;

    // 
    // 
    // @param[in] direction 
    // @param[in] dt 
    void ProcessKeyboard(Movement direction, float dt) override;

    // 
    // 
    // @param[in] dx 
    // @param[in] dy 
    void ProcessMouseMovement(float dx, float dy) override;

    // 
    // 
    // @param[in] dy 
    void ProcessMouseScroll(float dy) override;
};

#endif