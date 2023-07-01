/**
 * @file Particle.h
 * Created on 05/16/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "glm/glm.hpp"
#include <vector>

class Particle {
    public:
        // Default constructor
        Particle();

        // Destructor
        ~Particle();

        void update(float dt);
    private:
        std::vector<glm::vec2> m_externalForces;

        glm::vec2 m_position;

        glm::vec2 m_velocity;

        float m_mass;
}; // end Particle class

#endif