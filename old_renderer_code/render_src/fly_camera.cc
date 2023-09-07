// @file fly_camera.cc
// Created on 02/03/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/fly_camera.h"

#include <iostream>

FlyCamera::FlyCamera(const glm::vec3& position, const glm::vec3& direction) {
  position_ = position;
  front_ = glm::vec3(0.0f, 0.0f, -1.0f);
  //front_ = direction;
  up_ = glm::vec3(0.0f, 1.0f, 0.0f);
  world_up_ = glm::vec3(0.0f, 1.0f, 0.0f);
  yaw_ = 45.0f;
  pitch_ = 0.0f;
  movement_speed_ = 2.5f;
  sensitivity_ = 0.1f;
  zoom_ = 45.0f;

  Update();
}

FlyCamera::~FlyCamera() {

}

glm::vec3 FlyCamera::get_position() const {
  return position_;
}

glm::mat4 FlyCamera::get_view_matrix() const {
  return glm::lookAt(position_, position_ + front_, up_);
}

glm::mat4 FlyCamera::get_projection_matrix() const {

}

void FlyCamera::Update() {
  // calculate the new Front vector
  glm::vec3 new_front;
  new_front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
  new_front.y = sin(glm::radians(pitch_));
  new_front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
  front_ = glm::normalize(new_front);
  // also re-calculate the Right and Up vector
  right_ = glm::normalize(glm::cross(front_, world_up_));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
  up_ = glm::normalize(glm::cross(right_, front_));

  /*
  std::cout << "Front: " << front_.x << " " << front_.y << " " << front_.z << "\n";
  std::cout << "Position: " << position_.x << " " << position_.y << " " << position_.z << "\n";
  std::cout << "Up: " << up_.x << " " << up_.y << " " << up_.z << "\n";
  std::cout << "World Up: " << world_up_.x << " " << world_up_.y << " " << world_up_.z << "\n";
  std::cout << "Yaw: " << yaw_ << "\n";
  std::cout << "Pitch: " << pitch_ << "\n\n";
  */
}

void FlyCamera::ProcessKeyboard(Movement direction, float dt) {
  float velocity = movement_speed_ * dt;

  if (direction == Movement::kForward) {
    position_ += front_ * velocity;
  }
      
  if (direction == Movement::kBackward) {
    position_ -= front_ * velocity;
  }

  if (direction == Movement::kLeft) {
    position_ -= right_ * velocity;
  }
      
  if (direction == Movement::kRight) {
    position_ += right_ * velocity;
  }
}

void FlyCamera::ProcessMouseMovement(float dx, float dy) {
  dx *= sensitivity_;
  dy *= sensitivity_;

  yaw_ += dx;
  pitch_ += dy;

  // make sure that when pitch is out of bounds, screen doesn't get flipped
  if (pitch_ > 89.0f) {
    pitch_ = 89.0f;
  }
      
  if (pitch_ < -89.0f) {
    pitch_ = -89.0f;
  }
      
  // update Front, Right and Up Vectors using the updated Euler angles
  Update();
}

void FlyCamera::ProcessMouseScroll(float dy) {
  zoom_ -= dy;

  if (zoom_ < 1.0f) {
    zoom_ = 1.0f;
  }
      
  if (zoom_ > 45.0f) {
    zoom_ = 45.0f;
  }
}