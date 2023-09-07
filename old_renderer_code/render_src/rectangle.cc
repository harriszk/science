// @file rectangle.cc
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/rectangle.h"

#include <iostream>

Rectangle::Rectangle(float width, float height) : width_(width), height_(height) {
  degrees_rotated_ = 0.0f;
  UpdateModelMatrix();

  vertices_.push_back({-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f});
  vertices_.push_back({-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});
  vertices_.push_back({1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});
  vertices_.push_back({1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f});

  triangles_.push_back({0, 1, 2});
  triangles_.push_back({0, 2, 3});

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

Rectangle::~Rectangle() {

}

void Rectangle::set_width(float width) {
  width_ = width;
}

void Rectangle::set_height(float height) {
  height_ = height;
}

void Rectangle::Render() {
  UpdateModelMatrix();
  vao_.Bind();
  glDrawElements(GL_TRIANGLES, triangles_.size() * 3, GL_UNSIGNED_INT, 0);
}

void Rectangle::UpdateModelMatrix() {
  // Scaling operations > Rotations > Translations (matrices go in opposite order)
  model_matrix_ = glm::mat4(1.0f);

  model_matrix_ = glm::translate(model_matrix_, glm::vec3(position_, 0.0f));
  model_matrix_ = glm::rotate(model_matrix_, glm::radians(degrees_rotated_), glm::vec3(0.0f, 0.0f, 1.0f));
  model_matrix_ = glm::scale(model_matrix_, glm::vec3(width_, height_, 1.0f));

  //glm::mat4 skew = glm::mat4(glm::mat3(1.0f, 0.5f, 0.0f, 0.2f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f));
  //model_matrix_ = model_matrix_ * skew;
  //model_matrix_ = glm::rotate(model_matrix_, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}