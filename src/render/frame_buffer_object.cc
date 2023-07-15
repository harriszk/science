// @file frame_buffer_object.cc
// Created on 07/13/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/frame_buffer_object.h"

FrameBufferObject::FrameBufferObject() {
  glGenFramebuffers(1, &id_);
}

FrameBufferObject::~FrameBufferObject() {

}

void FrameBufferObject::Bind() {
  glBindFramebuffer(GL_FRAMEBUFFER, id_);
}

void FrameBufferObject::Unbind() {

}

void FrameBufferObject::AttachColorTexture(GLuint texture_id) {

}

void FrameBufferObject::AttachDepthBuffer(GLuint render_buffer_id) {

}

bool FrameBufferObject::IsComplete() const {
  return false;
}
