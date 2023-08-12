// @file display.cc
// Created on 08/05/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "display.h"

#include "logger.h"
#include "events/key_pressed_event.h"
#include "events/key_released_event.h"
#include "events/mouse_button_pressed_event.h"
#include "events/mouse_button_released_event.h"
#include "events/mouse_moved_event.h"
#include "events/mouse_scrolled_event.h"
#include "events/window_closed_event.h"
#include "events/window_focus_changed_event.h"
#include "events/window_moved_event.h"
#include "events/window_resized_event.h"

Display::Display(const char* title, int width, int height)
    : data_{title, width, height, nullptr} {
  Initialize();
}

Display::~Display() {
  glfwDestroyWindow(window_);
  glfwTerminate();
  window_ = nullptr;
}

void Display::Update() {
  //LOG_TRACE("Display update called!");

  glfwSwapBuffers(window_);
  glfwPollEvents();
}

void Display::set_event_callback(const EventCallback& callback) {
  data_.event_callback_ = callback;
}

void Display::Initialize() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  window_ = glfwCreateWindow(data_.width_, data_.height_, data_.title_, NULL, NULL);
  if (window_ == NULL) {
    LOG_ERROR("Failed to create GLFW window!");
    glfwTerminate();
    return;
  }
  LOG_INFO("Successfully created GLFW window!");

  glfwMakeContextCurrent(window_);
  glfwSetWindowUserPointer(window_, &data_);

  SetCallbacks();
}

const char* Display::get_title() {
  return data_.title_;
}

int Display::get_width() {
  return data_.width_;
}

int Display::get_height() {
  return data_.height_;
}

GLFWwindow* Display::get_window() {
  return window_;
}

Display::EventCallback Display::get_callback() {
  return data_.event_callback_;
}

void Display::SetCallbacks() {
  glfwSetWindowCloseCallback(window_, [](GLFWwindow* window) {
    DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);
    WindowClosedEvent event;
    data.event_callback_(event);
  });

  glfwSetWindowSizeCallback(window_, [](GLFWwindow* window, int width, int height) {
    DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);
    data.width_ = width;
    data.height_ = height;

    WindowResizedEvent event(width, height);
    data.event_callback_(event);
  });

  glfwSetKeyCallback(window_, [](GLFWwindow* window, int key, int scancode, int action, int mod) {
    DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

    switch (action) {
      case GLFW_PRESS:
      {
        KeyPressedEvent event((KeyCode)key, (Modifier)mod, false);
        data.event_callback_(event);
        break;
      }

      case GLFW_RELEASE:
      {
        KeyReleasedEvent event((KeyCode)key, (Modifier)mod);
        data.event_callback_(event);
        break;
      }

      case GLFW_REPEAT:
      {
        KeyPressedEvent event((KeyCode)key, (Modifier)mod, true);
        data.event_callback_(event);
        break;
      }
    }
  });

  glfwSetMouseButtonCallback(window_, [](GLFWwindow* window, int button, int action, int mod)
  {
    DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

    switch (action) {
      case GLFW_PRESS:
      {
        MouseButtonPressedEvent event((MouseButton)button, (Modifier)mod);
        data.event_callback_(event);
        break;
      }

      case GLFW_RELEASE:
      {
        MouseButtonReleasedEvent event((MouseButton)button, (Modifier)mod);
        data.event_callback_(event);
        break;
      }
    }
  });

  glfwSetScrollCallback(window_, [](GLFWwindow* window, double x_offset, double y_offset) {
    DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

    MouseScrolledEvent event((float)y_offset);
    data.event_callback_(event);
  });

  glfwSetCursorPosCallback(window_, [](GLFWwindow* window, double x, double y) {
    DisplayData& data = *(DisplayData*)glfwGetWindowUserPointer(window);

    MouseMovedEvent event((float)x, (float)y);
    data.event_callback_(event);
  });
}