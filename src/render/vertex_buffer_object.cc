// @file vertex_buffer_object.cc
// Created on 01/30/2023
// 
// Implementation of the VertexBufferObject class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/vertex_buffer_object.h"

#include <glad/glad.h>

VertexBufferObject::VertexBufferObject() {
  glGenBuffers(1, &id_);
}

VertexBufferObject::~VertexBufferObject() {
  glDeleteBuffers(1, &id_);
}

void VertexBufferObject::Bind() {
  glBindBuffer(GL_ARRAY_BUFFER, id_);
}

void VertexBufferObject::Unbind() {
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBufferObject::set_data(std::vector<Vertex>* vertices) {
  Bind();
  //glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
  glBufferData(GL_ARRAY_BUFFER, vertices->size() * sizeof(Vertex), &vertices->front(), GL_STATIC_DRAW);
}