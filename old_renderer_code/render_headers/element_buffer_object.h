// @file element_buffer_object.h
// Created on 01/29/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _ELEMENT_BUFFER_OBJECT_H_
#define _ELEMENT_BUFFER_OBJECT_H_

#include <vector>

#include "triangle.h"

class ElementBufferObject {
  public:
    // Default constructor.
    // 
    // Generates a new OpenGL element buffer object.
    ElementBufferObject();

    // Destructor.
    //
    // Deletes/deallocates the OpenGL element buffer object resources.
    ~ElementBufferObject();

    // Binds the element buffer object to the current OpenGL context.
    void Bind();

    // Unbinds the element buffer object from the current OpenGL context.
    void Unbind();

    // Sets the index data for the element buffer object using triangles.
    // 
    // @param[in] triangles The list of triangles to be set as the element data for the buffer.
    void set_data(std::vector<Triangle>* triangles);
    //void set_data(const void* data, int size);
    //void set_data(std::vector<Line>* lines);
  private:
    // The identifier of the element buffer object.
    uint32_t id_;
};

#endif