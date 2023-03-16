/**
 * @file Rectangle.cpp
 * Created on 03/15/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Rectangle.h"

#include <iostream>

Rectangle::Rectangle(float width, float height):
    m_width(width),
    m_height(height)
{
    m_degreesRotated = 0.0f;
    updateModelMatrix();

    m_vertices.push_back({-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f});
    m_vertices.push_back({-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});
    m_vertices.push_back({1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});
    m_vertices.push_back({1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f});

    m_triangles.push_back({0, 1, 2});
    m_triangles.push_back({0, 2, 3});

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
} // end initializing constructor

Rectangle::~Rectangle()
{

} // end destructor

void Rectangle::setWidth(float width)
{
    m_width = width;
} // end setWidth

void Rectangle::setHeight(float height)
{
    m_height = height;
} // end setHeight

void Rectangle::render()
{
    updateModelMatrix();
    m_vao.bind();
    glDrawElements(GL_TRIANGLES, m_triangles.size() * 3, GL_UNSIGNED_INT, 0);
} // end render

void Rectangle::updateModelMatrix()
{
    // Scaling operations > Rotations > Translations (matrices go in opposite order)
    m_modelMatrix = glm::mat4(1.0f);

    m_modelMatrix = glm::translate(m_modelMatrix, glm::vec3(m_position, 0.0f));
    m_modelMatrix = glm::rotate(m_modelMatrix, glm::radians(m_degreesRotated), glm::vec3(0.0f, 0.0f, 1.0f));
    m_modelMatrix = glm::scale(m_modelMatrix, glm::vec3(m_width, m_height, 1.0f));

    //glm::mat4 skew = glm::mat4(glm::mat3(1.0f, 0.5f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f));
    //m_modelMatrix = m_modelMatrix * skew;
    //m_modelMatrix = glm::rotate(m_modelMatrix, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
} // end updateModelMatrix