// @file application.cc
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "application.h"

#include "logger.h"

Application::Application() : display_("Science Application", 800, 550) {
  Initialize();
}

Application::~Application() {

}

void Application::Initialize() {
  LOG_TRACE("Initializing application.");

  display_.set_event_callback([this](const Event& event) {
    //event_manager_.Notify(event);
  });
}

void Application::Run() {
  LOG_TRACE("Application run method called.");

  if (display_.get_window() == NULL) {
    running_ = false;
  }

  while (running_) {
    display_.Update();
  }
}

void Application::OnWindowClose() {
  running_ = false;
}