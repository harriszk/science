// @file particle.h
// Created on 05/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include <vector>

#include "glm/glm.hpp"

class Particle {
  public:
    // Default constructor
    Particle();

    // Destructor
    ~Particle();

    void update(float dt);

  private:
    std::vector<glm::vec2> external_forces_;

    glm::vec2 position_;

    glm::vec2 velocity_;

    float mass_;
}; // end Particle class

#endif