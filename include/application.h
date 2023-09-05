// @file application.h
// Created on 07/16/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include <vector>

#include "display.h"
#include "system.h"
#include "event_listener.h"
#include "events/event.h"
#include "events/window_closed_event.h"
#include "events/key_pressed_event.h"

#include "imgui_system.h"

int main(int argc, char * argv[]);

class Application : public EventListener {
  public:
    // Default constructor.
    // 
    Application();

    // Destructor.
    // 
    virtual ~Application() = default;

    // 
    // 
    // @param[in] system 
    void AddSystem(System* system);

    // 
    // 
    // @param[in] event 
    void OnEvent(const Event& event) override;
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
    // @param[in] event 
    void OnKeyPressed(const KeyPressedEvent& event);


    // 
    // 
    Display display_;

    // 
    // 
    std::vector<System*> systems_;

    ImGuiSystem imgui_system_;
    
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