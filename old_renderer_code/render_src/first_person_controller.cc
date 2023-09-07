// @file first_person_controller.cc
// Created on 02/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/first_person_controller.h"

#include <iostream>

FirstPersonController::FirstPersonController(Camera* camera) : camera_(camera) {

}

FirstPersonController::~FirstPersonController() {

}

void FirstPersonController::ProcessKeyboardInput(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    forward_ = true;
  } else {
    forward_ = false;
  }

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    left_ = true;
  } else {
    left_ = false;
  }
  
  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    backward_ = true;
  } else {
    backward_ = false;
  }
  
  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    right_ = true;
  } else {
    right_ = false;
  }
}

void FirstPersonController::ProcessMouseMovement(float x, float y) {
  if (first_mouse_) {
    previous_x_ = x;
    previous_y_ = y;
    first_mouse_ = false;
  }

  float dx = x - previous_x_;
  float dy = previous_y_ - y; // reversed since y-coordinates go from bottom to top
  previous_x_ = x;
  previous_y_ = y;

  camera_->ProcessMouseMovement(dx, dy);
}

void FirstPersonController::ProcessMouseScroll(float dy) {
  camera_->ProcessMouseScroll(dy);
}

void FirstPersonController::UpdateCamera(float dt) {
  if (forward_) {
    //std::cout << "Move forward\n";
    camera_->ProcessKeyboard(Movement::kForward, dt);
  }

  if (left_) {
    //std::cout << "Move left\n";
    camera_->ProcessKeyboard(Movement::kLeft, dt);
  }

  if (backward_) {
    //std::cout << "Move backward\n";
    camera_->ProcessKeyboard(Movement::kBackward, dt);
  }

  if (right_) {
    //std::cout << "Move right\n";
    camera_->ProcessKeyboard(Movement::kRight, dt);
  }
}