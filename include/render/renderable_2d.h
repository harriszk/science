// @file renderable_2d.h
// Created on 01/29/2023
// 
// 
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _RENDERABLE_2D_H_
#define _RENDERABLE_2D_H_

#include "renderable.h"

class Renderable2D : public Renderable {
  public:
    virtual void Render() override = 0;

    virtual void set_position(float x, float y) {
      position_.x = x;
      position_.y = y;
    }

    virtual void setRotation(float angle) {
      degrees_rotated_ = angle;
    }

    virtual float getRotation() {
      return degrees_rotated_;
    }

    virtual glm::vec2 getPosition() {
      return position_;
    }

  protected:
    glm::vec2 position_;

    float degrees_rotated_;
};

#endif