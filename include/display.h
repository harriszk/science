// @file display.h
// Created on 08/05/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <functional>
#include <string>

#include <GLFW/glfw3.h>

#include "events/event.h"

class Display {
  public:
    using EventCallback = std::function<void(Event&)>;

    // Default constructor.
    Display(const char* title, int width, int height);

    // Destructor.
    ~Display();

    // 
    // 
    void Update();

    // Set the Event Callback
    // 
    // @param[in] callback 
    void set_event_callback(const EventCallback& callback);

    // Get the title
    // 
    // @return const char* 
    const char* get_title();

    // Get the width
    // 
    // @return int 
    int get_width();

    // Get the height
    // 
    // @return int 
    int get_height();

    // Get the window
    // 
    // @return GLFWwindow* 
    GLFWwindow* get_window();

    // Get the callback
    // 
    // @return EventCallback 
    EventCallback get_callback();
  private:
    // 
    // 
    void Initialize();

    // Set the Callbacks
    // 
    void SetCallbacks();

    // Pointer to the GLFW window.
    GLFWwindow* window_;

    struct DisplayData {
      // The title of the display.
      const char* title_;

      // The width of the display.
      int width_;

      // The height of the display.
      int height_;

			// The function to be called when an event happens.
      EventCallback event_callback_;
		};

    DisplayData data_;
};

#endif