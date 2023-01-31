#include "Display.h"
#include "Renderer.h"
#include "Scene.h"
#include "Model.h"

int main(int argc, char * argv[])
{
    Display display(800, 600, "Hello World!");
    Shader shader("shaders/vertexShaderSource.glsl", "shaders/fragmentShaderSource.glsl");
    Renderer renderer(display, shader);

    Scene scene;

    Model model;
    model.addVertex({-0.5f, -0.5f, 0.0f});
    model.addVertex({-0.5f, 0.5f, 0.0f});
    model.addVertex({0.5f, 0.5f, 0.0f});
    model.addVertex({0.5f, -0.5f, 0.0f});
    model.addTriangle({1, 2, 3});
    model.addTriangle({1, 3, 0});
    scene.addModel(model);

    renderer.addScene(scene);


    renderer.startRendering();

    return 0;
} // end main