/**
 * @file Scene.h
 * Created on 01/29/2023
 * 
 * This class is responsible for managing a single scene. It contains objects/models, lighting, and camera 
 * information needed to render a complete image. It acts as a container for all the elements that 
 * make up a single visual environment.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _SCENE_H_
#define _SCENE_H_

#include "Model.h"
#include "Camera.h"

// ** Should this class be responsible for user input? **

class Scene {
    public:
        // Default constructor
        Scene();

        // Destructor
        ~Scene();

        void update(float dt);

        bool addModel(Model *model);

        bool removeModel(const Model &model);

        void setCamera(Camera *camera);

        glm::mat4 getViewMatrix();

        std::vector<Model *> & getModels();
    private:
        std::vector<Model *> m_models;

        Camera *m_camera;
}; // end Scene class

#endif