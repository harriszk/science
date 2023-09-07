// @file coordinate_system_2d.cc
// Created on 04/10/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/coordinate_system_2d.h"

CoordinateSystem2D::CoordinateSystem2D(float min_x, float max_x, float min_y, float max_y) {
  for (float x = min_x; x <= max_x; x++) {
    vertices_.push_back({x, min_y, 0.0f, 1.0f, 1.0f, 1.0f});
    vertices_.push_back({x, max_y, 0.0f, 1.0f, 1.0f, 1.0f});
    number_of_lines_++;
  }

  for (float y = min_y; y <= max_y; y++) {
    vertices_.push_back({min_x, y, 0.0f, 1.0f, 1.0f, 1.0f});
    vertices_.push_back({max_x, y, 0.0f, 1.0f, 1.0f, 1.0f});
    number_of_lines_++;
  }

  vao_.Bind();

  vbo_.Bind();
  vbo_.set_data(&vertices_);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
  
  vbo_.Unbind();
  vao_.Unbind();
}

CoordinateSystem2D::~CoordinateSystem2D() {
    
}

void CoordinateSystem2D::Render() {
  vao_.Bind();
  glDrawArrays(GL_LINES, 0, 2 * number_of_lines_);
}