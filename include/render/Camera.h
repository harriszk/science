// @file camera.h
// Created on 01/29/2023
// 
// This class represents a virtual camera in 3D space. It determines the view and projection 
// matrices used to render the scene. The view matrix transforms world space to camera space 
// and the projection matrix transforms camera space to clip space. See: https://learnopengl.com/Getting-started/Camera
// for more info. It also provides methods for manipulating the camera's position and orientation, 
// such as moving forward, backward, strafing, etc.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

enum Movement {
  kForward,
  kBackward,
  kLeft,
  kRight,
  kUp,
  kDown
};

class Camera {
  public:
    // Gets the current position of the camera.
    // 
    // @return glm::vec3 The current position vector of the camera.
    virtual glm::vec3 get_position() const = 0;

    // Gets the view matrix of the camera.
    // 
    // @return glm::mat4 The view matrix of the camera.
    virtual glm::mat4 get_view_matrix() const = 0;

    // Gets the projection matrix of the camera.
    // 
    // @return glm::mat4 The projection matrix of the camera.
    virtual glm::mat4 get_projection_matrix() const = 0;

    // Updates the camera's state.
    // 
    // @param[in] dt The change in time, in seconds, since the last update.
    virtual void Update() = 0;

    // Processes input from any keyboard-like input system. Input parameters are 
    // abstracted away to a Movement enum.
    // 
    // @param[in] direction The direction to move the camera in.
    // @param[in] dt The change in time since the last update.
    virtual void ProcessKeyboard(Movement direction, float dt) = 0;

    // Processes mouse movement input for the camera.
    // 
    // @param[in] dx The change in x position of the mouse.
    // @param[in] dy The change in y position of the mouse.
    virtual void ProcessMouseMovement(float dx, float dy) = 0;

    // Processes mouse scroll input for the camera.
    // 
    // @param[in] dy The change in y position of the mouse wheel.
    virtual void ProcessMouseScroll(float dy) = 0;
  protected:
    // Camera Attributes
    glm::vec3 position_;
    glm::vec3 front_;
    glm::vec3 up_;
    glm::vec3 right_;
    glm::vec3 world_up_;

    // Euler Angles
    float yaw_;
    float pitch_;
    float roll_;

    // Camera Options
    float movement_speed_;
    float sensitivity_;
    float zoom_;
};

#endif