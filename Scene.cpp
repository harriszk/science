/**
 * @file Scene.cpp
 * Created on 01/31/2023
 * 
 * Implementation of the Scene class.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#include "Scene.h"

Scene::Scene()
{

} // end default constructor

Scene::~Scene()
{

} // end destructor

void Scene::update(float dt)
{

} // end update

bool Scene::addRenderable(Renderable *renderable)
{
    m_renderables.push_back(renderable);
    return true;
} // end addRenderable

bool Scene::removeRenderable(const Renderable &renderable)
{
    //m_models.erase(std::remove(m_models.begin(), m_models.end(), model), m_models.end());
    return true;
} // end removeRenderable

void Scene::setCamera(Camera *camera)
{
    m_camera = camera;
} // end setCamera

glm::mat4 Scene::getViewMatrix()
{
    if(!m_camera)
    {
        // No camera!
        return glm::mat4(1.0f);
    } // end if

    return m_camera->getViewMatrix();
} // end getViewMatrix

std::vector<Renderable *> & Scene::getRenderables()
{
    return m_renderables;
} // end getRenderables