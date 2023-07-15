// @file line.h
// Created on 03/15/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _LINE_H_
#define _LINE_H_

#include <cstdint>

#include "renderable.h"

class Line : public Renderable {
  public:
    // Default constructor.
    // 
    // @param[in] p1 
    // @param[in] p2 
    Line(const Vertex& p1, const Vertex& p2);

    // Destructor.
    ~Line();

    // 
    // 
    void Render() override;

  private:

};

#endif