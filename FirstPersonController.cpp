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

FirstPersonController::FirstPersonController()
{

} // end default constructor

FirstPersonController::~FirstPersonController()
{

} // end destructor

void FirstPersonController::processInput(GLFWwindow *window)
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

//Camera *camera, 
void FirstPersonController::updateCamera(float dt)
{
    if(m_forward)
    {
        std::cout << "Move forward\n";
        //camera->processKeyboard(Movement::FORWARD, dt);
    } // end if

    if(m_left)
    {
        std::cout << "Move left\n";
        //camera->processKeyboard(Movement::LEFT, dt);
    } // end if

    if(m_backward)
    {
        std::cout << "Move backward\n";
        //camera->processKeyboard(Movement::BACKWARD, dt);
    } // end if

    if(m_right)
    {
        std::cout << "Move right\n";
        //camera->processKeyboard(Movement::RIGHT, dt);
    } // end if
} // end updateCamera