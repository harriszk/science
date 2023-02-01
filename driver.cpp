#include "Display.h"
#include "Renderer.h"
#include "Scene.h"
#include "Model.h"

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "Vertex.h"
#include "Triangle.h"
#include <vector>

int main(int argc, char * argv[])
{
    Display display(800, 600, "Hello World!");
    Shader shader("shaders/vertexShaderSource.glsl", "shaders/fragmentShaderSource.glsl");
    Renderer renderer(display, shader);
    Scene scene;
    Model model, model2, model3;
    
    model.addVertex({-0.5f, -0.5f, 0.0f});
    model.addVertex({-0.5f, 0.5f, 0.0f});
    model.addVertex({0.5f, 0.5f, 0.0f});
    model.addVertex({0.5f, -0.5f, 0.0f});
    model.addTriangle({1, 2, 3});
    model.addTriangle({1, 3, 0});

    model2.addVertex({0.5f, 0.5f, 0.0f});
    model2.addVertex({0.5f, 1.0f, 0.0f});
    model2.addVertex({1.0f, 0.5f, 0.0f});
    model2.addTriangle({0, 1, 2});

    model3.addVertex({-0.7f, 0.7f, 0.0f});
    model3.addVertex({0.0f, 0.35f, 0.0f});
    model3.addVertex({-0.7f, 0.0f, 0.0f});
    model3.addVertex({0.0f, -0.2f, 0.0f});
    model3.addVertex({-0.6f, -0.3f, 0.0f});
    model3.addTriangle({0, 1, 2});
    model3.addTriangle({2, 1, 3});
    model3.addTriangle({2, 3, 4});

    scene.addModel(&model);
    scene.addModel(&model2);
    scene.addModel(&model3);
    
    renderer.addScene(scene);
    renderer.startRendering();
    
    return 0;
} // end main