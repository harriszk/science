// @file render_manager.h
// Created on 09/08/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _RENDER_MANAGER_H_
#define _RENDER_MANAGER_H_

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "display.h"
#include "render/shader.h"

class RenderManager {
  public:
    RenderManager(Display& display);

    ~RenderManager();

    void Render();
  private:
    Shader shader_;

    GLuint fbo_;
    GLuint rbo_;
    GLuint texture_id_;

    unsigned int VBO, VAO;
};

#endif