// @file entry_point.h
// Created on 07/16/2023
// 
// 
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

  auto app = CreateApplication();
  app->Run();
	delete app;

  return 0;
} // end main

#endif