// @file model.cc
// Created on 01/30/2023
// 
// Implementation of the Model class. 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/model.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>

Model::Model() : has_changed_(false) {
  model_matrix_ = glm::mat4(1.0f);
  //model_matrix_ = glm::rotate(model_matrix_, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
}

Model::~Model() {

}

bool Model::AddVertex(const Vertex& vertex) {
  vertices_.push_back(vertex);
  has_changed_ = true;

  // TODO: Check if a vertex with same positions is already apart of the model.

  return true;
}

bool Model::AddTriangle(const Triangle& triangle) {
  triangles_.push_back(triangle);
  has_changed_ = true;
  // TODO: Check if triangle with same indices is already apart of the model.

  return true;
}

std::vector<Vertex>& Model::get_vertices() {
  return vertices_;
}

std::vector<Triangle>& Model::get_triangles() {
  return triangles_;
}

void Model::LoadModel(const char* filename) {
  std::ifstream in;
  in.open(filename, std::ifstream::in);

  if (in.fail()) {
    std::cerr << "ERROR::MODEL::FILE_NOT_SUCCESSFULLY_READ: " << filename << std::endl;
    return;
  }

  std::string line;

  while (!in.eof()) {
    std::getline(in, line);
    std::istringstream iss(line.c_str());
    char trash;

    if (!line.compare(0, 2, "v ")) {
      iss >> trash;
      Vertex v;

      iss >> v.x;
      iss >> v.y;
      iss >> v.z;

      vertices_.push_back(v);
    } else if (!line.compare(0, 2, "f ")) {
      iss >> trash;
      Triangle f;
      
      iss >> f.v0;
      iss >> f.v1;
      iss >> f.v2;

      f.v0--;
      f.v1--;
      f.v2--;

      triangles_.push_back(f);
    }
  }

  has_changed_ = true;
}

void Model::Render() {
  if (has_changed_) {
    Upload();
    has_changed_ = false;
  }

  /*
  for(int i = 0; i < vertices_.size(); i++)
  {
      std::cout << vertices_[i].x << " " << vertices_[i].y << " " << vertices_[i].z << "\n"; 
  }
  std::cout << "\n";
  */

  //glDrawArrays(GL_TRIANGLES, 0, vertices_.size());
  //std::cout << "Drawing elements...\n";
  vao_.Bind();
  glDrawElements(GL_TRIANGLES, triangles_.size() * 3, GL_UNSIGNED_INT, 0);
}

void Model::Upload() {
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