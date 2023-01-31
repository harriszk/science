/**
 * @file VertexBufferObject.cpp
 * Created on 01/30/2023
 * 
 * Implementation of the VertexBufferObject class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "VertexBufferObject.h"
#include <glad/glad.h>

VertexBufferObject::VertexBufferObject()
{
    glGenBuffers(1, &m_id);
} // end default constructor

VertexBufferObject::~VertexBufferObject()
{
    glDeleteBuffers(1, &m_id);
} // end destructor

void VertexBufferObject::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_id);
} // end bind

void VertexBufferObject::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
} // end unbind

void VertexBufferObject::setData(std::vector<Vertex> *vertices)
{
    bind();
    //glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(Vertex), &vertices->front(), GL_STATIC_DRAW);

    //unbind();
} // end setData