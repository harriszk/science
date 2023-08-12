// @file modifier.h
// Created on 08/01/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _MODIFIER_H_
#define _MODIFIER_H_

enum class Modifier {
  None = 0,
  SHIFT_MOD = 1,
  CONTROL_MOD = 2,
  ALT_MOD = 4,
  SUPER_MOD = 8,
  CAPS_LOCK_MOD = 16,
  NUM_LOCK_MOD = 32
};

#endif