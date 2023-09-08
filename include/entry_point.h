// @file entry_point.h
// Created on 07/16/2023
// 
// This file serves as the entry point for the application. It contains the
// main() function responsible for initializing, running, and cleaning up the
// application. The actual application instance is created by the
// CreateApplication() function, which should be implemented elsewhere.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _ENTRY_POINT_H_
#define _ENTRY_POINT_H_

#include "application.h"
#include "logger.h"

extern Application* CreateApplication();

int main(int argc, char * argv[])
{
  Logger::Initialize();

  Application* app = CreateApplication();
  app->Run();
	delete app;

  Logger::Shutdown();

  return 0;
} // end main

#endif