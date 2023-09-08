// @file frame_buffer_object.h
// Created on 07/13/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _FRAME_BUFFER_OBJECT_H_
#define _FRAME_BUFFER_OBJECT_H_

#include <vector>

#include <glad/glad.h>

class FrameBufferObject {
  public:
    // Default constructor.
    // 
    // Generates a new OpenGL frame buffer object.
    FrameBufferObject();

    // Destructor.
    // 
    // Deletes/deallocates the OpenGL frame buffer object resources.
    ~FrameBufferObject();
    
    // Binds the OpenGL frame buffer object.
    // This makes it the active frame buffer object and any subsequent
    // frame buffer operations will be performed on it.
    void Bind();

    // Unbinds the OpenGL frame buffer object.
    // This makes the currently bound frame buffer object unbound,
    // so that no frame buffer object is bound.
    void Unbind();

    // Attaches a texture as a color attachment to the frame buffer object.
    // 
    // @param[in] texture_id The OpenGL ID of the texture to attach.
    void AttachColorTexture(GLuint texture_id);

    // Attaches a render buffer as a depth attachment to the frame buffer object.
    // 
    // @param[in] render_buffer_id The OpenGL ID of the render buffer to attach.
    void AttachDepthBuffer(GLuint render_buffer_id);

    // Checks if the frame buffer object is complete and ready to be used.
    // 
    // @return true if the frame buffer object is complete
    // @return false if the frame buffer object is not complete
    bool IsComplete() const;

  private:
    GLuint id_;
};

#endif 