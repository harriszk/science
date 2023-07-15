// @file particle.cc
// Created on 05/18/2023
// 
// Implementation of the Particle class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "physics/particle.h"

#include <iostream>

Particle::Particle() {
  mass_ = 50.0f;
  external_forces_.push_back(glm::vec2(0.0f, -1 * mass_ * 9.81f));
  velocity_ = glm::vec2(500.0f, 500.0f);
  position_ = glm::vec2(0.0f);
}

Particle::~Particle() {

}

void Particle::update(float dt) {
  glm::vec2 dv = (external_forces_.at(0) * dt ) / mass_;
  velocity_ += dv;
  position_ = position_ + (velocity_ * dt);

  std::cout << position_.x << ", " << position_.y << "\n";
}