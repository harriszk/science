// @file application.cc
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "application.h"

#include "logger.h"

Application::Application() {
  Initialize();
}

Application::~Application() {

}

void Application::OnEvent(Event& event) {
  LOG_INFO(event.ToString());
}

void Application::Initialize() {
  LOG_TRACE("Initializing application.");
}

void Application::Run() {
  LOG_TRACE("Application run method called.");
}