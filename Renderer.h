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

#include "Display.h"
#include "Scene.h"
#include "Shader.h"
#include "Model.h"

class Renderer {
    public:
        /**
         * Default constructor.
         * 
         * @param[in] display A reference to a Display object that the renderer will use for rendering.
         */
        Renderer(Display &display, Shader &shader);

        // Destructor.
        ~Renderer();

        /**
         * Starts the rendering loop. Continuously draws the scene
         * until the window is closed.
         * 
         */
        void startRendering();

        // Renders the scene.
        void render();

        void addScene(const Scene &scene);
    private:
        // Array of scenes
        std::vector<Scene> m_scenes;

        // The display used to render to.
        Display &m_display;

        Shader &m_shader;

        float m_dt;

        float m_lastFrame;
        //Camera m_camera;
}; // end Renderer class

#endif