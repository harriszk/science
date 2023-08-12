// @file display_test.cc
// Created on 08/06/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include <gtest/gtest.h>

#include "display.h"
#include "logger.h"
#include "events/window_closed_event.h"

TEST(DisplayTest, Constructor) {
  Logger::Initialize();

  const char* title = "Test Display";
  int width = 800;
  int height = 600;

  Display display(title, width, height);

  ASSERT_TRUE(display.get_window());
  EXPECT_EQ(display.get_width(), width);
  EXPECT_EQ(display.get_height(), height);
  EXPECT_EQ(display.get_title(), title);

  Logger::Shutdown();
}

TEST(DisplayTest, SetEventCallbackTest) {
  Logger::Initialize();

  Display display("Test Display", 800, 600);

  bool callback_called = false;

  Display::EventCallback test_callback = [&](Event& event) {
    callback_called = true;
  };

  display.set_event_callback(test_callback);

  Display::EventCallback display_callback = display.get_callback();
  WindowClosedEvent test_event;
  display_callback(test_event);

  EXPECT_TRUE(callback_called);

  Logger::Shutdown();
}
