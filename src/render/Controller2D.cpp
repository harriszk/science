/**
 * @file Controller2D.cpp
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/render/Controller2D.h"

#include <iostream>

Controller2D::Controller2D(Camera *camera):
    m_camera(camera)
{

}

Controller2D::~Controller2D()
{

}

void Controller2D::processKeyboardInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        m_up = true;
    } else {
        m_up = false;
    } // end if

    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        m_left = true;
    } else {
        m_left = false;
    } // end if
    
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        m_down = true;
    } else {
        m_down = false;
    } // end if
    
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        m_right = true;
    } else {
        m_right = false;
    } // end if
}

void Controller2D::processMouseMovement(float x, float y)
{

}

void Controller2D::processMouseScroll(float dy)
{

}

void Controller2D::updateCamera(float dt)
{
    if(m_up)
    {
        //std::cout << "Move Upd\n";
        m_camera->processKeyboard(Movement::UP, dt);
    } // end if

    if(m_left)
    {
        //std::cout << "Move left\n";
        m_camera->processKeyboard(Movement::LEFT, dt);
    } // end if

    if(m_down)
    {
        //std::cout << "Move down\n";
        m_camera->processKeyboard(Movement::DOWN, dt);
    } // end if

    if(m_right)
    {
        //std::cout << "Move right\n";
        m_camera->processKeyboard(Movement::RIGHT, dt);
    } // end if
}