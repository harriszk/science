#ifndef _MOUSE_EVENT_H_
#define _MOUSE_EVENT_H_

#include "event.h"
#include "modifier.h"

class MouseEvent : public Event {
  public:
    // Get the modifier
    // 
    // @return Modifier 
    Modifier get_modifier();
  protected:
    // Default constructor
    MouseEvent(Modifier modifier, EventType type);

    // 
    Modifier modifier_;
};

#endif