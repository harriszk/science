// @file application.h
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "display.h"
#include "events/event.h"
#include "events/window_closed_event.h"

int main(int argc, char * argv[]);

class Application {
  public:
    // Default constructor.
    // 
    Application();

    // Destructor.
    // 
    ~Application();
  private:
    // 
    // 
    void Initialize();

    // 
    // 
    void Run();

    // 
    // 
    void OnWindowClose();

    // 
    // 
    Display display_;

    // 
    // 
    bool running_ = true;

    /*
    Camera2D camera_;
    Controller2D controller_;
    Shader shader_;
    Renderer renderer_;
    Scene scene_;
    Model model; 
    Model model2;
    Model model3;
    */

    friend int ::main(int argc, char * argv[]);
};

Application* CreateApplication();

#endif