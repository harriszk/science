// @file application.cc
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "application.h"

#include <functional>

#include "events/window_resized_event.h"
#include "event_manager.h"
#include "logger.h"
#include "editor/menu_bar_panel.h"
#include "editor/scene_panel.h"
#include "editor/asset_panel.h"

Application::Application() : display_("Science Application", 1200, 725) {
  Initialize();
}

void Application::AddSystem(System* system) {
  systems_.push_back(system);
}

void Application::Initialize() {
  LOG_TRACE("Initializing application.");

  imgui_system_.AddPanel(new MenuBarPanel());
  imgui_system_.AddPanel(new ScenePanel());
  imgui_system_.AddPanel(new AssetPanel());

  systems_.push_back(&imgui_system_);

  display_.set_event_callback(std::bind(&EventManager::Dispatch, EventManager::Get(), std::placeholders::_1));

  EventManager* manager = EventManager::Get();
  manager->Subscribe(this, EventType::WindowClosed);
  manager->Subscribe(this, EventType::KeyPressed);

  int monitor_width, monitor_height;
  glfwGetFramebufferSize(display_.get_window(), &monitor_width, &monitor_height);

  WindowResizedEvent event(display_.get_width(), display_.get_height());
  event.set_monitor_width(monitor_width);
  event.set_monitor_height(monitor_height);
  manager->Dispatch(event);
}

void Application::Run() {
  LOG_TRACE("Application run method called.");

  if (display_.get_window() == nullptr) {
    running_ = false;
  }

  while (running_) {
    glClearColor(173.0f/255.0f, 216.0f/255.0f, 230.0f/255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for (System* system : systems_) {
      system->OnUpdate();
    }

    display_.Update();
  }
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

void Application::OnWindowClose() {
  running_ = false;
}

void Application::OnKeyPressed(const KeyPressedEvent& event) {
  if (event.get_key_code() == KeyCode::ESCAPE) {
    OnWindowClose();
  }
}