// @file system.h
// Created on 08/14/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

class System {
  public:
    virtual ~System() {}

    virtual void OnUpdate() = 0;
};

#endif