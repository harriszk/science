/**
 * @file FirstPersonController.cpp
 * Created on 02/03/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "FirstPersonController.h"
#include <iostream>

FirstPersonController::FirstPersonController(Camera *camera):
    m_camera(camera)
{

} // end default constructor

FirstPersonController::~FirstPersonController()
{

} // end destructor

void FirstPersonController::processKeyboardInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        m_forward = true;
    } else {
        m_forward = false;
    } // end if

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        m_left = true;
    } else {
        m_left = false;
    } // end if
    
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        m_backward = true;
    } else {
        m_backward = false;
    } // end if
    
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        m_right = true;
    } else {
        m_right = false;
    } // end if
} // end processInput

void FirstPersonController::processMouseMovement(float x, float y)
{
    if(m_firstMouse)
    {
        m_lastX = x;
        m_lastY = y;
        m_firstMouse = false;
    } // end if

    float dx = x - m_lastX;
    float dy = m_lastY - y; // reversed since y-coordinates go from bottom to top
    m_lastX = x;
    m_lastY = y;

    m_camera->processMouseMovement(dx, dy);
} // end processMouseMovement

void FirstPersonController::processMouseScroll(float dy)
{
    m_camera->processMouseScroll(dy);
} // end processMouseScroll

//Camera *camera, 
void FirstPersonController::updateCamera(float dt)
{
    if(m_forward)
    {
        //std::cout << "Move forward\n";
        m_camera->processKeyboard(Movement::FORWARD, dt);
    } // end if

    if(m_left)
    {
        //std::cout << "Move left\n";
        m_camera->processKeyboard(Movement::LEFT, dt);
    } // end if

    if(m_backward)
    {
        //std::cout << "Move backward\n";
        m_camera->processKeyboard(Movement::BACKWARD, dt);
    } // end if

    if(m_right)
    {
        //std::cout << "Move right\n";
        m_camera->processKeyboard(Movement::RIGHT, dt);
    } // end if
} // end updateCamera