// @file system.h
// Created on 08/14/2023
// 
// Defines the abstract base class for major systems in the application. A
// system represents a fundamental part of the application that requires
// periodic updates during the main loop, such as audio processing, physics
// simulation, etc.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

class System {
  public:
    virtual ~System() {}

    // Update method called during the application's main loop.
    virtual void OnUpdate() = 0;

    //virtual void OnImGuiRender() = 0;
};

#endif