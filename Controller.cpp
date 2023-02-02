/**
 * @file Controller.cpp
 * Created on 02/01/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Controller.h"
#include <iostream>

Controller::Controller()
{

} // end default constructor

Controller::~Controller()
{

} // end destructor

void Controller::handleInput(GLFWwindow *window, float dt)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        std::cout << "W pressed\n";
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        std::cout << "S pressed\n";
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        std::cout << "A pressed\n";
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        std::cout << "D pressed\n";;
} // end processInput