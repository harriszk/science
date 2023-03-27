/**
 * @file Camera2D.cpp
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/render/Camera2D.h"

#include <iostream>

Camera2D::Camera2D()
{
    m_position = glm::vec3(0.0f, 0.0f, 10.0f);
    m_front = glm::vec3(0.0f, 0.0f, -1.0f);
    //m_front = direction;
    m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    m_worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    m_yaw = 0.0f;
    m_pitch = 0.0f;
    m_movementSpeed = 2.5f;
    m_sensitivity = 0.1f;
    m_zoom = 45.0f;
    update();
}

Camera2D::~Camera2D()
{

}

glm::vec3 Camera2D::getPosition() const
{
    return m_position;
}

glm::mat4 Camera2D::getViewMatrix() const
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

glm::mat4 Camera2D::getProjectionMatrix() const
{

}

void Camera2D::update()
{
    // calculate the new Front vector
    //glm::vec3 new_front;
    //new_front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    //new_front.y = sin(glm::radians(m_pitch));
    //new_front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    //m_front = glm::normalize(new_front);
    // also re-calculate the Right and Up vector
    m_right = glm::normalize(glm::cross(m_front, m_worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_up = glm::normalize(glm::cross(m_right, m_front));
}

void Camera2D::processKeyboard(Movement direction, float dt)
{
    float velocity = m_movementSpeed * dt;

    if(direction == UP)
    {
        m_position += m_up * velocity;
    } // end if

    if(direction == DOWN)
    {
        m_position -= m_up * velocity;
    } // end if

    if(direction == LEFT)
    {
        m_position -= m_right * velocity;
    } // end if

    if(direction == RIGHT)
    {
        m_position += m_right * velocity;
    } // end if

    //std::cout << m_position.x << " " << m_position.y << " " << m_position.z << "\n";
}

void Camera2D::processMouseMovement(float dx, float dy)
{

}

void Camera2D::processMouseScroll(float dy)
{

}