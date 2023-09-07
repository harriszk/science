// @file camera_2d.cc
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include <iostream>

#include "render/camera_2d.h"

Camera2D::Camera2D() {
  position_ = glm::vec3(0.0f, 0.0f, 5.0f);
  front_ = glm::vec3(0.0f, 0.0f, -1.0f);
  //front_ = direction;
  up_ = glm::vec3(0.0f, 1.0f, 0.0f);
  world_up_ = glm::vec3(0.0f, 1.0f, 0.0f);
  yaw_ = 0.0f;
  pitch_ = 0.0f;
  movement_speed_ = 2.5f;
  sensitivity_ = 0.1f;
  zoom_ = 45.0f;
  Update();
}

Camera2D::~Camera2D() {

}

glm::vec3 Camera2D::get_position() const {
  return position_;
}

glm::mat4 Camera2D::get_view_matrix() const {
  return glm::lookAt(position_, position_ + front_, up_);
}

glm::mat4 Camera2D::get_projection_matrix() const {
  return glm::mat4(1.0f);
}

void Camera2D::Update() {
  // calculate the new Front vector
  //glm::vec3 new_front;
  //new_front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
  //new_front.y = sin(glm::radians(pitch_));
  //new_front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
  //front_ = glm::normalize(new_front);
  // also re-calculate the Right and Up vector
  right_ = glm::normalize(glm::cross(front_, world_up_));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
  up_ = glm::normalize(glm::cross(right_, front_));
}

void Camera2D::ProcessKeyboard(Movement direction, float dt) {
  float velocity = movement_speed_ * dt;

  if (direction == kUp) {
    position_ += up_ * velocity;
  }

  if (direction == kDown) {
    position_ -= up_ * velocity;
  }

  if (direction == kLeft) {
    position_ -= right_ * velocity;
  }

  if (direction == kRight) {
    position_ += right_ * velocity;
  }

  //std::cout << position_.x << " " << position_.y << " " << position_.z << "\n";
}

void Camera2D::ProcessMouseMovement(float dx, float dy) {

}

void Camera2D::ProcessMouseScroll(float dy) {

}