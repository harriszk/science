/**
 * @file ElementBufferObject.cpp
 * Created on 01/30/2023
 * 
 * Implmentation of the ElementBufferObject class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "ElementBufferObject.h"
#include <glad/glad.h>

ElementBufferObject::ElementBufferObject()
{
    glGenBuffers(1, &m_id);
} // end default constructor

ElementBufferObject::~ElementBufferObject()
{
    glDeleteBuffers(1, &m_id);
} // end destructor

void ElementBufferObject::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
} // end bind

void ElementBufferObject::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
} // end unbind

void ElementBufferObject::setData(std::vector<Triangle> *triangles)
{
    bind();
    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangles->size() * sizeof(Triangle), &triangles->front(), GL_STATIC_DRAW);
} // end setData