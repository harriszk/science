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

// Probably do not want glad and GLFW here. Doesn't make sense!
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Application::Application() : display_("Science Application", 1200, 725), imgui_system_(0) {
  Initialize();
}

void Application::AddSystem(System* system) {
  systems_.push_back(system);
}

void Application::Initialize() {
  LOG_TRACE("Initializing application.");

  // HACKY JUST TO SEE RESULTS!!!
  GLuint m_FBO;
  GLuint m_RBO;
  GLuint m_texture_id;
  
  glGenFramebuffers(1, &m_FBO);
  glBindFramebuffer(GL_FRAMEBUFFER, m_FBO);

  glGenTextures(1, &m_texture_id);
  glBindTexture(GL_TEXTURE_2D, m_texture_id);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, display_.get_width(), display_.get_height(), 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture_id, 0);

  glGenRenderbuffers(1, &m_RBO);
  glBindRenderbuffer(GL_RENDERBUFFER, m_RBO);
  glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, display_.get_width(), display_.get_height());
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_RBO);

  if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    LOG_ERROR("ERROR::FRAMEBUFFER:: Framebuffer is not complete!");

  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glBindTexture(GL_TEXTURE_2D, 0);
  glBindRenderbuffer(GL_RENDERBUFFER, 0);

  imgui_system_.test(m_FBO);
  // END HACKY!!!

  imgui_system_.AddPanel(new MenuBarPanel());
  imgui_system_.AddPanel(new ScenePanel(m_texture_id));
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
    // TEMP: Move to where ever the scene is rendered.
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