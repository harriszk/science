/**
 * @file Renderer.h
 * Created on 01/29/2023
 * 
 * This class is responsible for rendering scenes and images on a display.
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "Shader.h"
#include "Scene.h"
#include "Model.h"

class Renderer {
    public:
        /**
         * Default constructor.
         * 
         * @param[in] shader 
         */
        Renderer(Shader &shader);

        // Destructor.
        ~Renderer();

        // Renders the scene.
        void render();

        void addScene(Scene *scene);
    private:
        // Array of scenes
        std::vector<Scene*> m_scenes;

        Shader &m_shader;
}; // end Renderer class

#endif