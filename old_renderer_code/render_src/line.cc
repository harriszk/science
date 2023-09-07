// @file line.cc
// Created on 03/27/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/line.h"

Line::Line(const Vertex& p1, const Vertex& p2) {
  vertices_.push_back(p1);
  vertices_.push_back(p2);

  vao_.Bind();

  vbo_.Bind();
  vbo_.set_data(&vertices_);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  
  vbo_.Unbind();
  vao_.Unbind();
}

Line::~Line() {

}

void Line::Render() {
  vao_.Bind();
  glDrawArrays(GL_LINES, 0, 2);
}