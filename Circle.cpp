/**
 * @file Circle.cpp
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Circle.h"

float i = 0.1;

Circle::Circle(float radius):
    m_radius(radius)
{
    updateModelMatrix();
    uint32_t segments = 256;
    float x, y;
    float segmentAngle = 2.0f * glm::pi<float>() / segments;

    m_vertices.push_back({0.0f, 0.0f, 0.0f});

    for (uint32_t i = 0; i <= segments; i++) {
        x = std::cos(i * segmentAngle);
        y = std::sin(i * segmentAngle);

        m_vertices.push_back({x, y, 0.0f});
        m_triangles.push_back({0, i + 1, i + 2});
    } // end for

    m_vao.bind();

    m_vbo.bind();
    m_vbo.setData(&m_vertices);

    m_ebo.bind();
    m_ebo.setData(&m_triangles);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    m_vbo.unbind();
    m_vao.unbind();
} // end constructor

Circle::~Circle()
{

} // end destructor

void Circle::render()
{
    m_degreesRotated += i;
    updateModelMatrix();
    m_vao.bind();
    glDrawElements(GL_TRIANGLES, m_triangles.size() * 3, GL_UNSIGNED_INT, 0);
} // end render

void Circle::updateModelMatrix()
{
    // Scaling operations > Rotations > Translations (matrices go in opposite order)
    m_modelMatrix = glm::mat4(1.0f);

    m_modelMatrix = glm::translate(m_modelMatrix, glm::vec3(m_position, 0.0f));
    m_modelMatrix = glm::rotate(m_modelMatrix, glm::radians(m_degreesRotated), glm::vec3(0.0f, 0.0f, 1.0f));
    m_modelMatrix = glm::scale(m_modelMatrix, glm::vec3(m_radius, m_radius, 1.0f));
} // end updateModelMatrix