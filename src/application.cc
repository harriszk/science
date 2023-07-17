// @file application.cc
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "application.h"

#include "logger.h"
#include "events/key_pressed_event.h"
#include "events/key_released_event.h"
#include "events/key_typed_event.h"

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
  LOG_TRACE("Application run method called.");
}

void Application::Initialize() {
  LOG_TRACE("Initializing application.");

  KeyReleasedEvent event(G);
  LOG_INFO(event.ToString());
}