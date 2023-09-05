// @file event_manager_test.cc
// Created on 08/03/2023
// 
// Tests to ensure that the event manager is working properly.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include <gtest/gtest.h>

#include "event_manager.h"
#include "event_listener.h"
#include "logger.h"
#include "events/event.h"
#include "events/window_closed_event.h"

class MockEventListener : public EventListener {
  public:
    MockEventListener() {}

    void OnEvent(const Event& event) override {
      type_called_ = event.get_event_type();
      on_event_was_called_ = true;
    }

    bool on_event_was_called_ = false;
    EventType type_called_ = EventType::None;
};

TEST(EventManagerTest, SubscribeTest) {
  EventManager* manager = EventManager::Get();

  MockEventListener listener;

  ASSERT_TRUE(manager->Subscribe(&listener, EventType::WindowClosed));

  manager->UnsubscribeAll();
}

TEST(EventManagerTest, EventDispatchTest) {
  Logger::Initialize();

  EventManager* manager = EventManager::Get();

  MockEventListener listener;

  ASSERT_TRUE(manager->Subscribe(&listener, EventType::WindowClosed));

  WindowClosedEvent event;
  manager->Dispatch(event);

  ASSERT_TRUE(listener.on_event_was_called_);
  ASSERT_EQ(EventType::WindowClosed, listener.type_called_);

  manager->UnsubscribeAll();
  Logger::Shutdown();
}

TEST(EventManagerTest, UnsubscribeTest) {
  EventManager* manager = EventManager::Get();

  MockEventListener listener;

  ASSERT_TRUE(manager->Subscribe(&listener, EventType::WindowClosed));
  ASSERT_TRUE(manager->Unsubscribe(&listener, EventType::WindowClosed));
  ASSERT_FALSE(manager->Unsubscribe(&listener, EventType::KeyPressed));

  manager->UnsubscribeAll();
}

TEST(EventManagerTest, UnsubscribeAllTest) {
  EventManager* manager = EventManager::Get();

  MockEventListener first_listener;
  MockEventListener second_listener;

  manager->Subscribe(&first_listener, EventType::WindowClosed);
  manager->Subscribe(&second_listener, EventType::KeyPressed);

  ASSERT_TRUE(manager->UnsubscribeAll());
  ASSERT_FALSE(manager->Unsubscribe(&first_listener, EventType::WindowClosed));
  ASSERT_FALSE(manager->Unsubscribe(&second_listener, EventType::KeyPressed));
}

TEST(EventManagerTest, SubscribeMultipleHandlersTest) {
  EventManager* manager = EventManager::Get();

  MockEventListener first_listener;
  MockEventListener second_listener;
  MockEventListener third_listener;
  MockEventListener fourth_listener;

  ASSERT_TRUE(manager->Subscribe(&first_listener, EventType::KeyPressed));
  ASSERT_TRUE(manager->Subscribe(&second_listener, EventType::KeyPressed));
  ASSERT_TRUE(manager->Subscribe(&third_listener, EventType::KeyPressed));
  ASSERT_TRUE(manager->Subscribe(&fourth_listener, EventType::KeyPressed));

  manager->UnsubscribeAll();
}

TEST(EventManagerTest, UnsubscribeFromMultipleEventsTest) {
  EventManager* manager = EventManager::Get();

  MockEventListener listener;

  manager->Subscribe(&listener, EventType::WindowClosed);
  manager->Subscribe(&listener, EventType::KeyPressed);
  manager->Subscribe(&listener, EventType::KeyReleased);
  manager->Subscribe(&listener, EventType::MouseButtonPressed);
  manager->Subscribe(&listener, EventType::MouseScrolled);

  ASSERT_TRUE(manager->Unsubscribe(&listener, EventType::WindowClosed));
  ASSERT_TRUE(manager->Unsubscribe(&listener, EventType::KeyReleased));
  ASSERT_TRUE(manager->Unsubscribe(&listener, EventType::MouseScrolled));

  manager->UnsubscribeAll();
}

TEST(EventManagerTest, EventOrderingTest) {
  // There should be some precedence as to which listeners receive the
  // event first. They may then choose to handle the event and thus
  // conclude propagation of the event.
  FAIL();
}