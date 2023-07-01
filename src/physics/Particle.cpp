/**
 * @file Particle.cpp
 * Created on 05/18/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/physics/Particle.h"

#include <iostream>

Particle::Particle()
{
    m_mass = 50.0f;
    m_externalForces.push_back(glm::vec2(0.0f, -1 * m_mass * 9.81f));
    m_velocity = glm::vec2(500.0f, 500.0f);
    m_position = glm::vec2(0.0f);
} // end default constructor

Particle::~Particle()
{

} // end destructor

void Particle::update(float dt)
{
    glm::vec2 dv = (m_externalForces.at(0) * dt ) / m_mass;
    m_velocity += dv;
    m_position = m_position + (m_velocity * dt);

    std::cout << m_position.x << ", " << m_position.y << "\n";
} // end update