// @file vertex_array_object.cc
// Created on 01/30/2023
// 
// Implementation of the VertexArrayObject class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/vertex_array_object.h"

#include <glad/glad.h>

VertexArrayObject::VertexArrayObject() {
  glGenVertexArrays(1, &id_);
}

VertexArrayObject::~VertexArrayObject() {
  glDeleteVertexArrays(1, &id_);
}

void VertexArrayObject::Bind() {
  glBindVertexArray(id_);
}

void VertexArrayObject::Unbind() {
  glBindVertexArray(0);
}