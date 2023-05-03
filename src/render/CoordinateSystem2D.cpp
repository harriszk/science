/**
 * @file CoordinateSystem2D.cpp
 * Created on 04/10/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/render/CoordinateSystem2D.h"

CoordinateSystem2D::CoordinateSystem2D(float minX, float maxX, float minY, float maxY)
{
    for(float x = minX; x <= maxX; x++)
    {
        m_vertices.push_back({x, minY, 0.0f, 1.0f, 1.0f, 1.0f});
        m_vertices.push_back({x, maxY, 0.0f, 1.0f, 1.0f, 1.0f});
        numberOfLines++;
    }

    for(float y = minY; y <= maxY; y++)
    {
        m_vertices.push_back({minX, y, 0.0f, 1.0f, 1.0f, 1.0f});
        m_vertices.push_back({maxX, y, 0.0f, 1.0f, 1.0f, 1.0f});
        numberOfLines++;
    }

    m_vao.bind();

    m_vbo.bind();
    m_vbo.setData(&m_vertices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    m_vbo.unbind();
    m_vao.unbind();
} // end constructor

CoordinateSystem2D::~CoordinateSystem2D()
{
    
} // end destructor

void CoordinateSystem2D::render()
{
    m_vao.bind();
    glDrawArrays(GL_LINES, 0, 2 * numberOfLines);
} // end render