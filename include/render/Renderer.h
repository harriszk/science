// @file renderer.h
// Created on 01/29/2023
// 
// This class is responsible for rendering scenes and images on a display.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "shader.h"
#include "scene.h"
#include "model.h"

class Renderer {
  public:
    // Default constructor.
    // 
    // @param[in] shader
    Renderer(Shader &shader);

    // Destructor.
    ~Renderer();

    // Renders the scene.
    void Render();

    void AddScene(Scene *scene);

    void set_width(int width);

    void set_height(int height);
  private:
    // Array of scenes
    std::vector<Scene*> scenes_;

    Shader &shader_;

    int width_;

    int height_;
};

#endif