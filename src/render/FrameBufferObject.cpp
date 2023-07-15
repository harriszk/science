// @file FrameBufferObject.cpp
// Created on 07/13/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "../../include/render/FrameBufferObject.h"

FrameBufferObject::FrameBufferObject() 
{
  glGenFramebuffers(1, &m_id);
}

FrameBufferObject::~FrameBufferObject()
{

}

void FrameBufferObject::Bind()
{
  glBindFramebuffer(GL_FRAMEBUFFER, m_id);
}

void FrameBufferObject::Unbind()
{

}

void FrameBufferObject::AttachColorTexture(GLuint textureID)
{

}

void FrameBufferObject::AttachDepthBuffer(GLuint renderBufferID)
{

}

bool FrameBufferObject::IsComplete() const
{
  return false;
}
