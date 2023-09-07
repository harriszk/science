// @file element_buffer_object.cc
// Created on 01/30/2023
// 
// Implementation of the ElementBufferObject class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/element_buffer_object.h"

#include <glad/glad.h>

ElementBufferObject::ElementBufferObject() {
  glGenBuffers(1, &id_);
} // end default constructor

ElementBufferObject::~ElementBufferObject() {
  glDeleteBuffers(1, &id_);
} // end destructor

void ElementBufferObject::Bind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
} // end bind

void ElementBufferObject::Unbind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
} // end unbind

void ElementBufferObject::set_data(std::vector<Triangle>* triangles) {
  Bind();
  //glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangles->size() * sizeof(Triangle), &triangles->front(), GL_STATIC_DRAW);
} // end setData

/*
void ElementBufferObject::set_data(std::vector<Line> *lines) {
  Bind();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, lines->size() * sizeof(Line), &lines->front(), GL_STATIC_DRAW);
} // end setData
*/