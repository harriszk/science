// @file controller_2d.cc
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/controller_2d.h"

#include <iostream>

Controller2D::Controller2D(Camera* camera) : camera_(camera) {

}

Controller2D::~Controller2D() {

}

void Controller2D::ProcessKeyboardInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    up_ = true;
  } else {
    up_ = false;
  }

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    left_ = true;
  } else {
    left_ = false;
  }
  
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    down_ = true;
  } else {
    down_ = false;
  }
  
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    right_ = true;
  } else {
    right_ = false;
  }
}

void Controller2D::ProcessMouseMovement(float x, float y) {

}

void Controller2D::ProcessMouseScroll(float dy) {

}

void Controller2D::UpdateCamera(float dt) {
  if (up_) {
    //std::cout << "Move up\n";
    camera_->ProcessKeyboard(Movement::kUp, dt);
  }

  if (left_) {
    //std::cout << "Move left\n";
    camera_->ProcessKeyboard(Movement::kLeft, dt);
  }

  if (down_) {
    //std::cout << "Move down\n";
    camera_->ProcessKeyboard(Movement::kDown, dt);
  }

  if (right_) {
    //std::cout << "Move right\n";
    camera_->ProcessKeyboard(Movement::kRight, dt);
  }
}