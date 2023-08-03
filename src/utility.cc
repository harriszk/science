// @file utility.cc
// Created on 08/02/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "utility.h"

std::string KeyCodeToString(KeyCode key_code) {
  switch (key_code) {    
    case KeyCode::UNKNOWN: return "UNKNOWN";
    case KeyCode::SPACE: return " ";
    case KeyCode::APOSTROPHE: return "'";
    case KeyCode::COMMA: return ",";
    case KeyCode::MINUS: return "-";
    case KeyCode::PERIOD: return ".";
    case KeyCode::SLASH: return "/";
    case KeyCode::NUM_0: return "0";
    case KeyCode::NUM_1: return "1";
    case KeyCode::NUM_2: return "2";
    case KeyCode::NUM_3: return "3";
    case KeyCode::NUM_4: return "4";
    case KeyCode::NUM_5: return "5";
    case KeyCode::NUM_6: return "6";
    case KeyCode::NUM_7: return "7";
    case KeyCode::NUM_8: return "8";
    case KeyCode::NUM_9: return "9";
    case KeyCode::SEMICOLON: return ";";
    case KeyCode::EQUAL: return "=";
    case KeyCode::A: return "A";
    case KeyCode::B: return "B";
    case KeyCode::C: return "C";
    case KeyCode::D: return "D";
    case KeyCode::E: return "E";
    case KeyCode::F: return "F";
    case KeyCode::G: return "G";
    case KeyCode::H: return "H";
    case KeyCode::I: return "I";
    case KeyCode::J: return "J";
    case KeyCode::K: return "K";
    case KeyCode::L: return "L";
    case KeyCode::M: return "M";
    case KeyCode::N: return "N";
    case KeyCode::O: return "O";
    case KeyCode::P: return "P";
    case KeyCode::Q: return "Q";
    case KeyCode::R: return "R";
    case KeyCode::S: return "S";
    case KeyCode::T: return "T";
    case KeyCode::U: return "U";
    case KeyCode::V: return "V";
    case KeyCode::W: return "W";
    case KeyCode::X: return "X";
    case KeyCode::Y: return "Y";
    case KeyCode::Z: return "Z";
    case KeyCode::LEFT_BRACKET: return "[";
    case KeyCode::BACKSLASH: return "\\";
    case KeyCode::RIGHT_BRACKET: return "]";
    case KeyCode::GRAVE_ACCENT: return "`";
    case KeyCode::WORLD_1: return "NON-US CHARACTER #1";
    case KeyCode::WORLD_2: return "NON-US CHARACTER #2";
    case KeyCode::ESCAPE: return "ESC";
    case KeyCode::ENTER: return "ENTER";
    case KeyCode::TAB: return "TAB";
    case KeyCode::BACKSPACE: return "BACKSPACE";
    case KeyCode::INSERT: return "INSERT";
    case KeyCode::DELETE: return "DELETE";
    case KeyCode::KEY_RIGHT: return "RIGHT";
    case KeyCode::KEY_LEFT: return "LEFT";
    case KeyCode::KEY_DOWN: return "DOWN";
    case KeyCode::KEY_UP: return "UP";
    case KeyCode::PAGE_UP: return "PAGE UP";
    case KeyCode::PAGE_DOWN: return "PAGE DOWN";
    case KeyCode::HOME: return "HOME";
    case KeyCode::END: return "END";
    case KeyCode::CAPS_LOCK: return "CAPS LOCK";
    case KeyCode::SCROLL_LOCK: return "SCROLL LOCK";
    case KeyCode::NUM_LOCK: return "NUM LOCK";
    case KeyCode::PRINT_SCREEN: return "PRINT SCREEN";
    case KeyCode::PAUSE: return "PAUSE";
    case KeyCode::F1: return "F1";
    case KeyCode::F2: return "F2";
    case KeyCode::F3: return "F3";
    case KeyCode::F4: return "F4";
    case KeyCode::F5: return "F5";
    case KeyCode::F6: return "F6";
    case KeyCode::F7: return "F7";
    case KeyCode::F8: return "F8";
    case KeyCode::F9: return "F9";
    case KeyCode::F10: return "F10";
    case KeyCode::F11: return "F11";
    case KeyCode::F12: return "F12";
    case KeyCode::F13: return "F13";
    case KeyCode::F14: return "F14";
    case KeyCode::F15: return "F15";
    case KeyCode::F16: return "F16";
    case KeyCode::F17: return "F17";
    case KeyCode::F18: return "F18";
    case KeyCode::F19: return "F19";
    case KeyCode::F20: return "F20";
    case KeyCode::F21: return "F21";
    case KeyCode::F22: return "F22";
    case KeyCode::F23: return "F23";
    case KeyCode::F24: return "F24";
    case KeyCode::F25: return "F25";
    case KeyCode::KP_0: return "KEY PAD 0";
    case KeyCode::KP_1: return "KEY PAD 1";
    case KeyCode::KP_2: return "KEY PAD 2";
    case KeyCode::KP_3: return "KEY PAD 3";
    case KeyCode::KP_4: return "KEY PAD 4";
    case KeyCode::KP_5: return "KEY PAD 5";
    case KeyCode::KP_6: return "KEY PAD 6";
    case KeyCode::KP_7: return "KEY PAD 7";
    case KeyCode::KP_8: return "KEY PAD 8";
    case KeyCode::KP_9: return "KEY PAD 9";
    case KeyCode::KP_DECIMAL: return "KEY PAD .";
    case KeyCode::KP_DIVIDE: return "KEY PAD /";
    case KeyCode::KP_MULTIPLY: return "KEY PAD *";
    case KeyCode::KP_SUBTRACT: return "KEY PAD -";
    case KeyCode::KP_ADD: return "KEY PAD +";
    case KeyCode::KP_ENTER: return "KEY PAD ENTER";
    case KeyCode::KP_EQUAL: return "KEY PAD =";
    case KeyCode::LEFT_SHIFT: return "LEFT SHIFT";
    case KeyCode::LEFT_CONTROL: return " LEFT CTRL";
    case KeyCode::LEFT_ALT: return "LEFT ALT";
    case KeyCode::LEFT_SUPER: return "LEFT SUPER";
    case KeyCode::RIGHT_SHIFT: return "RIGHT SHIFT";
    case KeyCode::RIGHT_CONTROL: return "RIGHT CTRL";
    case KeyCode::RIGHT_ALT: return "RIGHT ALT";
    case KeyCode::RIGHT_SUPER: return "RIGHT SUPER";
    case KeyCode::MENU: return "MENU";
    default: return "UNKNOWN";
  }
}

std::string MouseButtonToString(MouseButton button) {
  switch (button) {
    case MouseButton::MOUSE_LEFT: return "LEFT";
    case MouseButton::MOUSE_RIGHT: return "RIGHT";
    default: return "UNKNOWN";
  }
}