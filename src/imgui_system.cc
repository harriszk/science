// @file imgui_system.cc
// Created on 08/14/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "imgui_system.h"

#include <GLFW/glfw3.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

#include "events/window_resized_event.h"
#include "events/mouse_button_pressed_event.h"
#include "events/mouse_button_released_event.h"
#include "events/mouse_moved_event.h"
#include "events/mouse_scrolled_event.h"
#include "events/key_pressed_event.h"
#include "events/key_released_event.h"
#include "events/key_typed_event.h"
#include "event_manager.h"

ImGuiSystem::ImGuiSystem() {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  io.KeyMap[ImGuiKey_Backspace] = KeyCode::BACKSPACE;
  io.KeyMap[ImGuiKey_LeftArrow] = KeyCode::KEY_LEFT;
  io.KeyMap[ImGuiKey_RightArrow] = KeyCode::KEY_RIGHT;
  io.KeyMap[ImGuiKey_UpArrow] = KeyCode::KEY_UP;
  io.KeyMap[ImGuiKey_DownArrow] = KeyCode::KEY_DOWN;
  io.KeyMap[ImGuiKey_PageUp] = KeyCode::PAGE_UP;
  io.KeyMap[ImGuiKey_PageDown] = KeyCode::PAGE_DOWN;
  io.KeyMap[ImGuiKey_Home] = KeyCode::HOME;
  io.KeyMap[ImGuiKey_End] = KeyCode::END;
  io.KeyMap[ImGuiKey_Insert] = KeyCode::INSERT;
  io.KeyMap[ImGuiKey_Delete] = KeyCode::DELETE;
  io.KeyMap[ImGuiKey_Enter] = KeyCode::ENTER;
  io.KeyMap[ImGuiKey_Escape] = KeyCode::ESCAPE;
  io.KeyMap[ImGuiKey_Tab] = KeyCode::TAB;
  io.KeyMap[ImGuiKey_LeftSuper] = KeyCode::LEFT_SUPER;
  io.KeyMap[ImGuiKey_RightSuper] = KeyCode::RIGHT_SUPER;
  io.KeyMap[ImGuiKey_A] = KeyCode::A;
  io.KeyMap[ImGuiKey_C] = KeyCode::C;
  io.KeyMap[ImGuiKey_V] = KeyCode::V;
  io.KeyMap[ImGuiKey_X] = KeyCode::X;

  //ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");

  EventManager::Get()->Subscribe(this, EventType::WindowResized);
  EventManager::Get()->Subscribe(this, EventType::MouseButtonPressed);
  EventManager::Get()->Subscribe(this, EventType::MouseButtonReleased);
  EventManager::Get()->Subscribe(this, EventType::MouseMoved);
  EventManager::Get()->Subscribe(this, EventType::MouseScrolled);
  EventManager::Get()->Subscribe(this, EventType::KeyPressed);
  EventManager::Get()->Subscribe(this, EventType::KeyReleased);
  EventManager::Get()->Subscribe(this, EventType::KeyTyped);
}

ImGuiSystem::~ImGuiSystem() {
  ImGui_ImplOpenGL3_Shutdown();
  //ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}

void ImGuiSystem::OnUpdate() {
  ImGui_ImplOpenGL3_NewFrame();
  //ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  ImGuiIO& io = ImGui::GetIO(); (void)io;
  float time = (float)glfwGetTime();
  io.DeltaTime = time - time_;
  time_ = time;

  static bool show = true;
  ImGui::ShowDemoWindow(&show);

  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiSystem::OnEvent(const Event& event) {
  switch (event.get_event_category()) {
    case EventCategory::Mouse:
      OnMouseEvent(event);
      break;
    case EventCategory::Keyboard:
      OnKeyboardEvent(event);
      break;
    case EventCategory::Window:
      if (event.get_event_type() == EventType::WindowResized) {
        const WindowResizedEvent& window_event = static_cast<const WindowResizedEvent&>(event);

        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(window_event.get_width(), window_event.get_height());
      }
      break;
    default:
      break;
  }
}

void ImGuiSystem::OnMouseEvent(const Event& event) {
  switch (event.get_event_type()) {
    case EventType::MouseButtonPressed: {
      const MouseButtonPressedEvent& mouse_event = static_cast<const MouseButtonPressedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.MouseDown[mouse_event.get_button()] = true;

      break;
    }
    case EventType::MouseButtonReleased: {
      const MouseButtonReleasedEvent& mouse_event = static_cast<const MouseButtonReleasedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.MouseDown[mouse_event.get_button()] = false;

      break;
    }
    case EventType::MouseMoved: {
      const MouseMovedEvent& mouse_event = static_cast<const MouseMovedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.MousePos = ImVec2(mouse_event.get_x(), mouse_event.get_y());

      break;
    }
    case EventType::MouseScrolled: {
      const MouseScrolledEvent& mouse_event = static_cast<const MouseScrolledEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.MouseWheel += mouse_event.get_dy();

      break;
    }
    default:
      break;
  }
}

void ImGuiSystem::OnKeyboardEvent(const Event& event) {
  switch (event.get_event_type()) {
    case EventType::KeyPressed: {
      const KeyPressedEvent& key_event = static_cast<const KeyPressedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.KeysDown[key_event.get_key_code()] = true;

      io.KeyCtrl = io.KeysDown[KeyCode::LEFT_CONTROL] || io.KeysDown[KeyCode::RIGHT_CONTROL];
      io.KeyShift = io.KeysDown[KeyCode::LEFT_SHIFT] || io.KeysDown[KeyCode::RIGHT_SHIFT];
      io.KeyAlt = io.KeysDown[KeyCode::LEFT_ALT] || io.KeysDown[KeyCode::RIGHT_ALT];
      io.KeySuper = io.KeysDown[KeyCode::LEFT_SUPER] || io.KeysDown[KeyCode::RIGHT_SUPER];
      break;
    }
    case EventType::KeyReleased: {
      const KeyPressedEvent& key_event = static_cast<const KeyPressedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      io.KeysDown[key_event.get_key_code()] = false;

      break;
    }
    case EventType::KeyTyped: {
      const KeyTypedEvent& key_event = static_cast<const KeyTypedEvent&>(event);

      ImGuiIO& io = ImGui::GetIO();
      
      int key_code = key_event.get_key_code();
      if (key_code > 0 && key_code < 0x10000) {
        io.AddInputCharacter((unsigned short)key_code);
      }

      break;
    }
    default:
      break;
  }
}