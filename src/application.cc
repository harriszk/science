// @file application.cc
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "application.h"

#include "logger.h"

Application::Application()
/*
    : display_(1150, 800, "Science Simulations"),
      controller_(&camera_),
      shader_("../src/render/shaders/vertexShaderSource.glsl", "../src/render/shaders/fragmentShaderSource.glsl"),
      renderer_(shader_) */{
  Initialize();
}

Application::~Application() {

}

void Application::Run() {
  LOG_INFO("Main run method called.");
  /*
  while (!display_.ShouldClose()) {
    display_.PaintFrame();
  } // end while
  */
}

void Application::Initialize() {
  /*
  display_.set_renderer(&renderer_);
  display_.set_controller(&controller_);
  scene_.set_camera(&camera_);
  renderer_.AddScene(&scene_);

  scene_.AddRenderable(&model);
  scene_.AddRenderable(&model2);
  scene_.AddRenderable(&model3);

  model.AddVertex({-0.5f, -0.5f, -0.5f, 0.75f, 0.0f, 0.0f}); // 0
  model.AddVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 1
  model.AddVertex({0.5f, 0.5f, -0.5f, 0.75f, 0.0f, 0.0f});   // 2
  model.AddVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 3
  model.AddVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.75f, 0.0f});  // 4
  model.AddVertex({-0.5f, 0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 5
  model.AddVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.75f, 0.0f});    // 6
  model.AddVertex({0.5f, -0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 7
  model.AddTriangle({4,0,7});
  model.AddTriangle({4,5,7});
  model.AddTriangle({4,5,0});
  model.AddTriangle({2,6,3});
  model.AddTriangle({2,6,1});
  model.AddTriangle({2,1,3});
  model.AddTriangle({5,0,7});
  model.AddTriangle({6,1,3});

  model2.AddVertex({1.0f, -1.0f, 0.0f});
  model2.AddVertex({1.0f, 1.0f, 0.0f});
  model2.AddVertex({3.0f, 1.0f, 0.0f});
  model2.AddVertex({3.0f, -1.0f, 0.0f});
  model2.AddTriangle({0, 1, 2});
  model2.AddTriangle({0, 2, 3});

  model3.AddVertex({-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f}); // 0
  model3.AddVertex({-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});  // 1
  model3.AddVertex({1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});   // 2
  model3.AddVertex({1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f});  // 3
  model3.AddTriangle({0,1,2});
  model3.AddTriangle({0,2,3});
  */
}