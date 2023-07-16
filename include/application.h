// @file application.h
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "render/display.h"

#include "render/renderer.h"
#include "render/scene.h"
#include "render/shader.h"
#include "render/camera_2d.h"
#include "render/controller_2d.h"
#include "render/model.h"

class Application {
  public:
    // Default constructor.
    // 
    Application();

    // Destructor.
    // 
    ~Application();

    // 
    // 
    void Run();

  private:
    // 
    // 
    void Initialize();

    // 
    // 
    Display display_;

    Camera2D camera_;
    Controller2D controller_;
    Shader shader_;
    Renderer renderer_;
    Scene scene_;
    Model model; 
    Model model2;
    Model model3;
};

#endif