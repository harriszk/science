// @file events_test.cc
// Created on 08/02/2023
// 
// Tests to ensure that the event system is working properly.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include <gtest/gtest.h>

#include "events/key_pressed_event.h"
#include "events/key_released_event.h"
#include "events/key_typed_event.h"
#include "events/mouse_button_pressed_event.h"
#include "events/mouse_button_released_event.h"
#include "events/mouse_moved_event.h"
#include "events/mouse_scrolled_event.h"
#include "events/window_closed_event.h"
#include "events/window_focus_changed_event.h"
#include "events/window_moved_event.h"
#include "events/window_resized_event.h"

TEST(EventSystemTest, KeyPressedEventTest) {
  KeyCode key = KeyCode::SPACE;
  Modifier mod = Modifier::None;
  KeyPressedEvent event(key, mod, false);
  
  EXPECT_EQ(event.get_event_type(), EventType::KeyPressed);
  EXPECT_EQ(event.get_event_category(), EventCategory::Keyboard);
  EXPECT_EQ(event.get_key_code(), key);
  EXPECT_EQ(event.get_modifier(), mod);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, KeyReleasedEventTest) {
  KeyCode key = KeyCode::W;
  Modifier mod = Modifier::None;
  KeyReleasedEvent event(key, mod);

  EXPECT_EQ(event.get_event_type(), EventType::KeyReleased);
  EXPECT_EQ(event.get_event_category(), EventCategory::Keyboard);
  EXPECT_EQ(event.get_key_code(), key);
  EXPECT_EQ(event.get_modifier(), mod);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, KeyTypedEventTest) {
  KeyCode key = KeyCode::W;
  KeyTypedEvent event(key);

  EXPECT_EQ(event.get_event_type(), EventType::KeyTyped);
  EXPECT_EQ(event.get_event_category(), EventCategory::Keyboard);
  EXPECT_EQ(event.get_key_code(), key);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, MouseMovedEventTest) {
  int x = 200;
  int y = 800;
  MouseMovedEvent event(x, y);

  EXPECT_EQ(event.get_event_type(), EventType::MouseMoved);
  EXPECT_EQ(event.get_event_category(), EventCategory::Mouse);
  EXPECT_EQ(event.get_x(), x);
  EXPECT_EQ(event.get_y(), y);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, MouseButtonPressedEventTest) {
  MouseButton button = MouseButton::MOUSE_LEFT;
  Modifier mod = Modifier::SHIFT_MOD;
  MouseButtonPressedEvent event(button, mod);

  EXPECT_EQ(event.get_event_type(), EventType::MouseButtonPressed);
  EXPECT_EQ(event.get_event_category(), EventCategory::Mouse);
  EXPECT_EQ(event.get_button(), button);
  EXPECT_EQ(event.get_modifier(), mod);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, MouseButtonReleasedEventTest) {
  MouseButton button = MouseButton::MOUSE_LEFT;
  Modifier mod = Modifier::CAPS_LOCK_MOD;
  MouseButtonReleasedEvent event(button, mod);

  EXPECT_EQ(event.get_event_type(), EventType::MouseButtonReleased);
  EXPECT_EQ(event.get_event_category(), EventCategory::Mouse);
  EXPECT_EQ(event.get_button(), button);
  EXPECT_EQ(event.get_modifier(), mod);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, MouseScrolledEventTest) {
  float y_offset = 0.5f;
  MouseScrolledEvent event(y_offset);

  EXPECT_EQ(event.get_event_type(), EventType::MouseScrolled);
  EXPECT_EQ(event.get_event_category(), EventCategory::Mouse);
  EXPECT_EQ(event.get_dy(), y_offset);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, WindowResizedEventTest) {
  int width = 800;
  int height = 600;
  WindowResizedEvent event(width, height);

  EXPECT_EQ(event.get_event_type(), EventType::WindowResized);
  EXPECT_EQ(event.get_event_category(), EventCategory::Window);
  EXPECT_EQ(event.get_width(), width);
  EXPECT_EQ(event.get_height(), height);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, WindowClosedEventTest) {
  WindowClosedEvent event;

  EXPECT_EQ(event.get_event_type(), EventType::WindowClosed);
  EXPECT_EQ(event.get_event_category(), EventCategory::Window);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, WindowMovedEventTest) {
  float x = 100;
  float y = 200;
  WindowMovedEvent event(x, y);

  EXPECT_EQ(event.get_event_type(), EventType::WindowMoved);
  EXPECT_EQ(event.get_event_category(), EventCategory::Window);
  EXPECT_EQ(event.get_x(), x);
  EXPECT_EQ(event.get_y(), y);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, WindowMinimizedEventTest) {
  WindowFocusChangeType focus_type = WindowFocusChangeType::Minimized;
  WindowFocusChangedEvent event(focus_type);

  EXPECT_EQ(event.get_event_type(), EventType::WindowFocusChanged);
  EXPECT_EQ(event.get_event_category(), EventCategory::Window);
  EXPECT_EQ(event.get_focus_type(), focus_type);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());
}

TEST(EventSystemTest, WindowMaximizedEventTest) {
  WindowFocusChangeType focus_type = WindowFocusChangeType::Maximized;
  WindowFocusChangedEvent event(focus_type);

  EXPECT_EQ(event.get_event_type(), EventType::WindowFocusChanged);
  EXPECT_EQ(event.get_event_category(), EventCategory::Window);
  EXPECT_EQ(event.get_focus_type(), focus_type);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());  
}

TEST(EventSystemTest, WindowFocusedLostEventTest) {
  WindowFocusChangeType focus_type = WindowFocusChangeType::FocusLost;
  WindowFocusChangedEvent event(focus_type);

  EXPECT_EQ(event.get_event_type(), EventType::WindowFocusChanged);
  EXPECT_EQ(event.get_event_category(), EventCategory::Window);
  EXPECT_EQ(event.get_focus_type(), focus_type);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());  
}

TEST(EventSystemTest, WindowFocusedGainedEventTest) {
  WindowFocusChangeType focus_type = WindowFocusChangeType::FocusGained;
  WindowFocusChangedEvent event(focus_type);

  EXPECT_EQ(event.get_event_type(), EventType::WindowFocusChanged);
  EXPECT_EQ(event.get_event_category(), EventCategory::Window);
  EXPECT_EQ(event.get_focus_type(), focus_type);
  EXPECT_FALSE(event.IsHandled());

  event.set_handled();
  EXPECT_TRUE(event.IsHandled());  
}