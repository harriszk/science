// @file application.cc
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "application.h"

#include "logger.h"
#include "events/key_pressed_event.h"
#include "events/mouse_button_pressed_event.h"

Application::Application() {
  Initialize();
}

Application::~Application() {

}

void Application::Run() {
  LOG_TRACE("Application run method called.");
}

void Application::Initialize() {
  LOG_TRACE("Initializing application.");

  KeyPressedEvent e1(KeyCode::D, false);
  MouseButtonPressedEvent e2(MouseButton::MOUSE_LEFT);

  LOG_INFO(e1.ToString());
  LOG_INFO(e2.ToString());
}