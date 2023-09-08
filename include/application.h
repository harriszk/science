// @file application.h
// Created on 07/16/2023
// 
// This class serves as the core of component of the software. It manages the
// initialization, execution, and coordination of various systems within the
// application. Users are expected to create a concrete application class that
// inherits from this base class to define their application's behavior. That
// is, you will need to add various systems to the application. There are
// several systems already created that you may add to your application or you
// may create a new system.
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

int main(int argc, char * argv[]);

class Application : public EventListener {
  public:
    // Default constructor.
    Application();

    // Destructor.
    virtual ~Application() = default;

    // Add a system to the application.
    // 
    // @param[in] system A pointer to a system to be added to the application.
    void AddSystem(System* system);

    // Event callback function.
    // 
    // @param[in] event The dispatched event.
    void OnEvent(const Event& event) override;
  private:
    // Initialize the application.
    void Initialize();

    // Run the application main loop.
    void Run();

    // Event handler for window close event.
    // Sets the running_ flag to false;
    void OnWindowClose();

    // Event handler for key pressed event.
    // 
    // @param[in] event The key pressed event.
    void OnKeyPressed(const KeyPressedEvent& event);

    // Display used by the application.
    Display display_;

    // List of systems managed by the application.
    std::vector<System*> systems_;
    
    // Flag indicating whether the application is running.
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