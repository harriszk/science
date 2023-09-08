// @file display.h
// Created on 08/05/2023
// 
// This class defines the display, which encapsulates the management of an
// application window. It allows for creating and managing the main application
// window, including setting its size, title, and handling events through event
// callbacks.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <functional>
#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "events/event.h"

class Display {
  public:
    using EventCallback = std::function<void(Event&)>;

    // Default constructor.
    Display(const char* title, int width, int height);

    // Destructor.
    ~Display();

    // Update the display.
    void Update();

    // Set the event callback.
    // 
    // @param[in] callback The event callback function.
    void set_event_callback(const EventCallback& callback);

    // Get the title for the display.
    // 
    // @return const char*
    const char* get_title();

    // Get the width of the display.
    // 
    // @return int
    int get_width();

    // Get the height of the display.
    // 
    // @return int
    int get_height();

    // Get the window.
    // 
    // @return GLFWwindow*
    GLFWwindow* get_window();

    // Get the event callback.
    // 
    // @return EventCallback
    EventCallback get_callback();
  private:
    // Initialize the display.
    void Initialize();

    // Set GLFW event callbacks.
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