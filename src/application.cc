// @file application.cc
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "application.h"

#include <functional>

// Probably do not want GLFW here. Doesn't make sense!
#include <GLFW/glfw3.h>

#include <iostream>

#include "events/window_resized_event.h"
#include "events/frame_buffer_changed_event.h"
#include "event_manager.h"
#include "logger.h"

Application::Application() : display_("Science Application", 1200, 725), render_manager_(display_) {
  Initialize();
}

void Application::Initialize() {
  LOG_TRACE("Initializing application.");

  display_.set_event_callback(std::bind(&EventManager::Dispatch, EventManager::Get(), std::placeholders::_1));

  EventManager* manager = EventManager::Get();
  manager->Subscribe(this, EventType::WindowClosed);
  manager->Subscribe(this, EventType::KeyPressed);
}

void Application::Run() {
  LOG_TRACE("Application run method called.");

  if (display_.get_window() == nullptr) {
    running_ = false;
  }

  // This is just here because the ImGuiSystem 'needs' this initially.
  // Should probably fix that and get rid of this code because it really
  // should not be necessary.
  EventManager* manager = EventManager::Get();

  int width, height;
  glfwGetFramebufferSize(display_.get_window(), &width, &height);
  FrameBufferChangedEvent frame_buffer_event(width, height);
  manager->Dispatch(frame_buffer_event);

  WindowResizedEvent window_event(display_.get_width(), display_.get_height());
  manager->Dispatch(window_event);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  while (running_) {
    for (System* system : systems_) {
      system->OnUpdate();
    }

    /*
    imgui_system_.Begin();
    for (System* system : systems_) {
      system->OnImGuiRender();
    }
    imgui_system_.End();
    */

    render_manager_.Render();

    display_.Update();
  }
}

void Application::AddSystem(System* system) {
  systems_.push_back(system);
}

void Application::OnEvent(const Event& event) {
  switch (event.get_event_type()) {
    case EventType::WindowClosed:
      OnWindowClose();
      break;
    case EventType::KeyPressed:
      OnKeyPressed(static_cast<const KeyPressedEvent&>(event));
      break;
    default:
      break;
  }
}

void Application::OnKeyPressed(const KeyPressedEvent& event) {
  if (event.get_key_code() == KeyCode::ESCAPE) {
    OnWindowClose();
  }
}

void Application::OnWindowClose() {
  running_ = false;
}

/**/