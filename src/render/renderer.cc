// @file renderer.cc
// Created on 01/30/2023
// 
// Implementation fo the Renderer class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/renderer.h"

#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Renderer::Renderer(Shader &shader) : shader_(shader), width_(800), height_(600) {

}

Renderer::~Renderer() {

}

void Renderer::Render() {
  glClearColor(173.0f/255.0f, 216.0f/255.0f, 230.0f/255.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  shader_.Use();

  // create transformations
  //glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
  //glm::mat4 view          = glm::mat4(1.0f);
  glm::mat4 projection    = glm::mat4(1.0f);
  //model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(0.5f, 1.0f, 0.0f));
  //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
  //view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
  projection = glm::perspective(glm::radians(45.0f), float(width_) / float(height_), 0.1f, 100.0f);

  glm::mat4 view = scenes_.at(0)->get_view_matrix();

  // retrieve the matrix uniform locations
  uint32_t model_location = glGetUniformLocation(shader_.get_id(), "model");
  uint32_t view_location  = glGetUniformLocation(shader_.get_id(), "view");
  uint32_t projection_location  = glGetUniformLocation(shader_.get_id(), "projection");
  // pass them to the shaders
  //glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(model));
  glUniformMatrix4fv(view_location, 1, GL_FALSE, glm::value_ptr(view));
  glUniformMatrix4fv(projection_location, 1, GL_FALSE, glm::value_ptr(projection));
  
  // Render models from the scene
  auto &renderables = scenes_.at(0)->get_renderables();
  for (auto &renderable : renderables) {
      glUniformMatrix4fv(model_location, 1, GL_FALSE, glm::value_ptr(renderable->get_model_matrix()));
      renderable->Render();
  } // end for

  /*
  std::vector<Vertex> vertices;
  std::vector<Triangle> triangles;

  
  int number_of_points = 0;
  auto &models = scenes_.at(0).getModels();
  for(auto &model : models)
  {
      std::vector<Vertex> &tempV = model.getVertices();
      for(auto vertex : tempV)
      {
          vertices.push_back(vertex);
      }

      std::vector<Triangle> &tempT = model.getTriangles();
      for(auto triangle : tempT)
      {
          triangle.v0 += number_of_points;
          triangle.v1 += number_of_points;
          triangle.v2 += number_of_points;
          triangles.push_back(triangle);
      }
      number_of_points = vertices.size();
  }
  
  m_vao.bind();
  m_vbo.setData(&vertices);
  m_ebo.setData(&triangles);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glDrawElements(GL_TRIANGLES, triangles.size() * 3, GL_UNSIGNED_INT, 0);
  */
}

void Renderer::AddScene(Scene* scene) {
  scenes_.push_back(scene);
}

void Renderer::set_width(int width) {
  width_ = width;
}

void Renderer::set_height(int height) {
  height_ = height;
}