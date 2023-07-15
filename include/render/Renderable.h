// @file renderable.h
// Created on 01/29/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _RENDERABLE_H_
#define _RENDERABLE_H_

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glad/glad.h"

#include "vertex_array_object.h"
#include "vertex_buffer_object.h"
#include "element_buffer_object.h"
#include "vertex.h"
#include "triangle.h"

class Renderable {
  public:
    // Renders the object.
    virtual void Render() = 0;

    // Gets the models transformation matrix.
    // 
    // @return glm::mat4 The model matrix of the model, transforming from the models local space to world space.
    glm::mat4 get_model_matrix() const {
      return model_matrix_;
    };
  
  protected:
    // The collection of vertices that make up the renderable object.
    std::vector<Vertex> vertices_;

    // The collection of triangles that make up the renderable object.
    std::vector<Triangle> triangles_;

    // The collection of lines that make up the renderable object.
    //std::vector<Line> lines_;

    // The vertex array object associated with the renderable object.
    VertexArrayObject vao_;

    // The vertex buffer object associated with the renderable object.
    VertexBufferObject vbo_;

    // The element buffer object associated with the renderable object.
    ElementBufferObject ebo_;

    // The models transformation matrix. It maps vertices from local space to world space.
    glm::mat4 model_matrix_ = glm::mat4(1.0f);
};

#endif