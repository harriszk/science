/**
 * @file Camera.h
 * Created on 01/29/2023
 * 
 * This class represents a virtual camera in 3D space. It determines the view and projection 
 * matrices used to render the scene. The view matrix transforms world space to camera space 
 * and the projection matrix transforms camera space to clip space. See: https://learnopengl.com/Getting-started/Camera
 * for more info. It also provides methods for manipulating the camera's position and orientation, 
 * such as moving forward, backward, strafing, etc.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "glm/glm.hpp"

#include <glm/gtc/matrix_transform.hpp>

enum Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN
}; // end Movement enum

class Camera {
    public:
        /**
         * Gets the current position of the camera.
         * 
         * @return glm::vec3 The current position vector of the camera.
         */
        virtual glm::vec3 getPosition() const = 0;

        /**
         * Gets the view matrix of the camera.
         * 
         * @return glm::mat4 The view matrix of the camera.
         */
        virtual glm::mat4 getViewMatrix() const = 0;

        /**
         * Gets the projection matrix of the camera.
         * 
         * @return glm::mat4 The projection matrix of the camera.
         */
        virtual glm::mat4 getProjectionMatrix() const = 0;

        /**
         * Updates the camera's state.
         * 
         * @param[in] dt The change in time, in seconds, since the last update.
         */
        virtual void update() = 0;

        /**
         * Processes input from any keyboard-like input system. Input parameters are 
         * abstracted away to a Movement enum.
         * 
         * @param[in] direction The direction to move the camera in.
         * @param[in] dt The change in time since the last update.
         */
        virtual void processKeyboard(Movement direction, float dt) = 0;

        /**
         * Processes mouse movement input for the camera.
         * 
         * @param[in] dx The change in x position of the mouse.
         * @param[in] dy The change in y position of the mouse.
         */
        virtual void processMouseMovement(float dx, float dy) = 0;

        /**
         * Processes mouse scroll input for the camera.
         * 
         * @param[in] dy The change in y position of the mouse wheel.
         */
        virtual void processMouseScroll(float dy) = 0;
    protected:
        // Camera Attributes
        glm::vec3 m_position;
        glm::vec3 m_front;
        glm::vec3 m_up;
        glm::vec3 m_right;
        glm::vec3 m_worldUp;

        // Euler Angles
        float m_yaw;
        float m_pitch;
        float m_roll;

        // Camera Options
        float m_movementSpeed;
        float m_sensitivity;
        float m_zoom;
}; // end Camera class

#endif