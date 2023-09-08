// @file vertex_array_object.h
// Created on 01/29/2023
// 
// This class represents an OpenGL vertex array object. A vertex array 
// object stores all the state needed to specify vertex data to the graphics 
// pipeline.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _VERTEX_ARRAY_OBJECT_H_
#define _VERTEX_ARRAY_OBJECT_H_

#include <cstdint>

class VertexArrayObject {
  public:
    // Default constructor.
    // 
    // Generates a new OpenGL vertex array object.
    VertexArrayObject();
    
    // Destructor.
    // 
    // Deletes/deallocates the OpenGL vertex array object.
    ~VertexArrayObject();

    // Binds the vertex array object to the current context.
    void Bind();

    // Unbinds the vertex array object from the current context.
    void Unbind();
  private:
    // The identifier of the vertex array object.
    uint32_t id_;
};

#endif