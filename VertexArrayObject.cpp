/**
 * @file VertexArrayObject.cpp
 * Created on 01/30/2023
 * 
 * Implementation of the VertexArrayObject class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "VertexArrayObject.h"
#include <glad/glad.h>

VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1, &m_id);
} // end default constructor

VertexArrayObject::~VertexArrayObject()
{
    glDeleteVertexArrays(1, &m_id);
} // end desetructor

void VertexArrayObject::bind()
{
    glBindVertexArray(m_id);
} // end bind

void VertexArrayObject::unbind()
{
    glBindVertexArray(0);
} // end unbind