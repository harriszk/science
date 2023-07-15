// @file scene.cc
// Created on 01/31/2023
// 
// Implementation of the Scene class.
// 
// © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
#include "render/scene.h"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::Update(float dt) {

}

bool Scene::AddRenderable(Renderable* renderable) {
  renderables_.push_back(renderable);
  return true;
}

bool Scene::RemoveRenderable(const Renderable& renderable) {
  //models_.erase(std::remove(models_.begin(), models_.end(), model), models_.end());
  return true;
}

void Scene::set_camera(Camera* camera) {
  camera_ = camera;
} 

glm::mat4 Scene::get_view_matrix() {
  if (!camera_) {
    // No camera!
    return glm::mat4(1.0f);
  } // end if

  return camera_->get_view_matrix();
}

std::vector<Renderable*>& Scene::get_renderables() {
  return renderables_;
}