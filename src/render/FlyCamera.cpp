/**
 * @file FlyCamera.cpp
 * Created on 02/03/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/render/FlyCamera.h"

#include <iostream>

FlyCamera::FlyCamera(const glm::vec3 &position, const glm::vec3 &direction)
{
    m_position = position;
    m_front = glm::vec3(0.0f, 0.0f, -1.0f);
    //m_front = direction;
    m_up = glm::vec3(0.0f, 1.0f, 0.0f);
    m_worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    m_yaw = 45.0f;
    m_pitch = 0.0f;
    m_movementSpeed = 2.5f;
    m_sensitivity = 0.1f;
    m_zoom = 45.0f;
    update();
} // end initializing constructor

FlyCamera::~FlyCamera()
{

} // end destructor

glm::vec3 FlyCamera::getPosition() const
{
    return m_position;
} // end getPosition

glm::mat4 FlyCamera::getViewMatrix() const
{
    return glm::lookAt(m_position, m_position + m_front, m_up);
} // end getViewMatrix

glm::mat4 FlyCamera::getProjectionMatrix() const
{

} // end getProjectionMatrix

void FlyCamera::update()
{
    // calculate the new Front vector
    glm::vec3 new_front;
    new_front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    new_front.y = sin(glm::radians(m_pitch));
    new_front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(new_front);
    // also re-calculate the Right and Up vector
    m_right = glm::normalize(glm::cross(m_front, m_worldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    m_up = glm::normalize(glm::cross(m_right, m_front));

    /*
    std::cout << "Front: " << m_front.x << " " << m_front.y << " " << m_front.z << "\n";
    std::cout << "Position: " << m_position.x << " " << m_position.y << " " << m_position.z << "\n";
    std::cout << "Up: " << m_up.x << " " << m_up.y << " " << m_up.z << "\n";
    std::cout << "World Up: " << m_worldUp.x << " " << m_worldUp.y << " " << m_worldUp.z << "\n";
    std::cout << "Yaw: " << m_yaw << "\n";
    std::cout << "Pitch: " << m_pitch << "\n\n";
    */
} // end update

void FlyCamera::processKeyboard(Movement direction, float dt)
{
    float velocity = m_movementSpeed * dt;

    if(direction == FORWARD)
    {
        m_position += m_front * velocity;
    } // end if
        
    if(direction == BACKWARD)
    {
        m_position -= m_front * velocity;
    } // end if

    if(direction == LEFT)
    {
        m_position -= m_right * velocity;
    } // end if
        
    if(direction == RIGHT)
    {
        m_position += m_right * velocity;
    } // end if
} // end processKeyboard

void FlyCamera::processMouseMovement(float dx, float dy)
{
    dx *= m_sensitivity;
    dy *= m_sensitivity;

    m_yaw += dx;
    m_pitch += dy;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if(m_pitch > 89.0f)
    {
        m_pitch = 89.0f;
    } // end if
        
    if(m_pitch < -89.0f)
    {
        m_pitch = -89.0f;
    } // end if
        
    // update Front, Right and Up Vectors using the updated Euler angles
    update();
} // end processMouseMovement

void FlyCamera::processMouseScroll(float dy)
{
    m_zoom -= dy;

    if(m_zoom < 1.0f)
    {
        m_zoom = 1.0f;
    } // end if
        
    if(m_zoom > 45.0f)
    {
        m_zoom = 45.0f;
    } // end if
} // end processMouseScroll