// @file utility.h
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <string>

#include "key_code.h"
#include "modifier.h"
#include "events/mouse_button_event.h"

std::string KeyCodeToString(KeyCode keyCode);

std::string MouseButtonToString(MouseButton button);

std::string ModifierToString(Modifier mod);

#endif