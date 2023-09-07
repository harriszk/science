// @file vertex_buffer_object.h
// Created on 01/29/2023
// 
// This class is responsible for managing and storing vertex data in a specific buffer.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _VERTEX_BUFFER_OBJECT_H_
#define _VERTEX_BUFFER_OBJECT_H_

#include <vector>

#include "vertex.h"

class VertexBufferObject {
  public:
    // Default constructor.
    // 
    // Generates a new OpenGL vertex buffer object.
    VertexBufferObject();

    // Destructor.
    // 
    // Deletes/deallocates the OpenGL vertex buffer object resources.
    ~VertexBufferObject();

    // Binds the OpenGL vertex buffer object. This makes it the active 
    // vertex buffer object and any subsequent vertex buffer operations 
    // will be performed on it.
    void Bind();

    // Unbinds the OpenGL vertex buffer object. This makes the currently 
    // bound vertex buffer object unbound, so that no vertex buffer object 
    // is bound.
    void Unbind();

    // Sets the data of the vertex buffer object. The specified data will 
    // replace the current data of the vertex buffer object.
    // 
    // @param[in] vertices A reference to the vertices to set as the data of the vertex buffer object.
    void set_data(std::vector<Vertex>* vertices);
    //void setData(const void *data, int size);
  private:
    // The identifier of the vertex buffer object.
    uint32_t id_;
}; // end VertexBufferObject class

#endif