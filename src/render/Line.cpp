/**
 * @file Line.cpp
 * Created on 03/27/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "../../include/render/Line.h"

Line::Line(const Vertex &p1, const Vertex &p2)
{
    m_vertices.push_back(p1);
    m_vertices.push_back(p2);

    m_vao.bind();

    m_vbo.bind();
    m_vbo.setData(&m_vertices);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    m_vbo.unbind();
    m_vao.unbind();
} // end initalizing constructor

Line::~Line()
{

} // end destructor

void Line::render()
{
    m_vao.bind();
    glDrawArrays(GL_LINES, 0, 2);
} // end render