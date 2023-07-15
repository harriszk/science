// @file circle.cc
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/circle.h"

Circle::Circle(float radius) : radius_(radius) {
  UpdateModelMatrix();
  uint32_t segments = 32;
  float x, y;
  float segment_angle = 2.0f * glm::pi<float>() / segments;

  vertices_.push_back({0.0f, 0.0f, 0.0f});

  for (uint32_t i = 0; i <= segments; i++) {
    x = std::cos(i * segment_angle);
    y = std::sin(i * segment_angle);

    vertices_.push_back({x, y, 0.0f});
    triangles_.push_back({0, i + 1, i + 2});
  } // end for

  vao_.Bind();

  vbo_.Bind();
  vbo_.set_data(&vertices_);

  ebo_.Bind();
  ebo_.set_data(&triangles_);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  vbo_.Unbind();
  vao_.Unbind();
}

Circle::~Circle() {

}

void Circle::Render() {
  UpdateModelMatrix();
  vao_.Bind();
  glDrawElements(GL_TRIANGLES, triangles_.size() * 3, GL_UNSIGNED_INT, 0);
}

void Circle::UpdateModelMatrix()
{
  // Scaling operations > Rotations > Translations (matrices go in opposite order)
  model_matrix_ = glm::mat4(1.0f);

  model_matrix_ = glm::translate(model_matrix_, glm::vec3(position_, 0.0f));
  model_matrix_ = glm::rotate(model_matrix_, glm::radians(degrees_rotated_), glm::vec3(0.0f, 0.0f, 1.0f));
  model_matrix_ = glm::scale(model_matrix_, glm::vec3(radius_, radius_, 1.0f));
}