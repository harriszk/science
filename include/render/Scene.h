// @file scene.h
// Created on 01/29/2023
// 
// This class is responsible for managing a single scene. It contains objects/models, lighting, and camera 
// information needed to render a complete image. It acts as a container for all the elements that 
// make up a single visual environment.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#ifndef _SCENE_H_
#define _SCENE_H_

#include "renderable.h"
#include "camera.h"

class Scene {
  public:
    // Default constructor
    Scene();

    // Destructor
    ~Scene();

    // 
    // 
    // @param[in] dt 
    void Update(float dt);

    // 
    // 
    // @param[in] renderable 
    // @return true 
    // @return false 
    bool AddRenderable(Renderable* renderable);

    // 
    // 
    // @param[in] renderable 
    // @return true 
    // @return false 
    bool RemoveRenderable(const Renderable &renderable);

    // Set the camera
    // 
    // @param[in] camera 
    void set_camera(Camera* camera);

    // Get the view matrix
    // 
    // @return glm::mat4 
    glm::mat4 get_view_matrix();

    // Get the renderables
    // 
    // @return std::vector<Renderable*>& 
    std::vector<Renderable*> & get_renderables();
  private:
    std::vector<Renderable*> renderables_;

    Camera* camera_;
};

#endif