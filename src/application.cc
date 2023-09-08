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

#include "events/window_resized_event.h"
#include "event_manager.h"
#include "logger.h"

Application::Application() : display_("Science Application", 1200, 725) {
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
  // Should probably fix that and get rid of this code because it is really
  // not necessary.
  EventManager* manager = EventManager::Get();
  int monitor_width, monitor_height;
  glfwGetFramebufferSize(display_.get_window(), &monitor_width, &monitor_height);

  WindowResizedEvent event(display_.get_width(), display_.get_height());
  event.set_monitor_width(monitor_width);
  event.set_monitor_height(monitor_height);
  manager->Dispatch(event);

  while (running_) {
    // TEMP: Move to where ever the scene is rendered.
    glClearColor(173.0f/255.0f, 216.0f/255.0f, 230.0f/255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // END TEMP
    
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