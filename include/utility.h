// @file utility.h
// Created on 08/02/2023
// 
// Utility functions for converting key codes, mouse buttons, and modifiers
// to string representations.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <string>

#include "key_code.h"
#include "modifier.h"
#include "events/mouse_button_event.h"

// Convert a KeyCode enumeration to its string representation.
// 
// @param[in] keyCode The KeyCode enumeration to convert.
// @return std::string The string representation of the KeyCode.
std::string KeyCodeToString(KeyCode keyCode);

// Convert a MouseButton enumeration to its string representation.
// 
// @param[in] button The MouseButton enumeration to convert.
// @return std::string The string representation of the MouseButton.
std::string MouseButtonToString(MouseButton button);

// Convert a Modifier enumeration to its string representation.
// 
// @param[in] mod The Modifier enumeration to convert.
// @return std::string The string representation of the Modifier.
std::string ModifierToString(Modifier mod);

#endif