#include "Display.h"
#include "Renderer.h"
#include "Scene.h"
#include "Model.h"
#include "Shader.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ElementBufferObject.h"
#include "Vertex.h"
#include "Triangle.h"
#include <vector>

#include "FirstPersonController.h"
#include "FlyCamera.h"
#include "Camera2D.h"
#include "Controller2D.h"
#include "Rectangle.h"
#include "Circle.h"

int main(int argc, char * argv[])
{
    //FlyCamera camera(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
    //FirstPersonController controller(&camera);

    Camera2D camera;
    Controller2D controller(&camera);

    Display display(800, 600, "Hello World!");
    Shader shader("shaders/vertexShaderSource.glsl", "shaders/fragmentShaderSource.glsl");
    Renderer renderer(shader);
    display.setRenderer(&renderer);
    display.setContorller(&controller);
    Scene scene;
    scene.setCamera(&camera);
    renderer.addScene(&scene);

    //Rectangle rect(0.5f, 0.25f);
    //scene.addRenderable(&rect);

    Circle circle(0.1f);
    scene.addRenderable(&circle);

    // Use either a start method or have which ever component is using
    // the display update it.
    //display.start();
    
    glEnable(GL_DEPTH_TEST);

    while(!display.shouldClose())
    {
        display.paintFrame();
    } // end while

    return 0;
} // end main

/*
Model model, model2, model3;

scene.addRenderable(&model);
scene.addRenderable(&model2);
scene.addRenderable(&model3);

model.addVertex({-0.5f, -0.5f, -0.5f, 0.75f, 0.0f, 0.0f}); // 0
model.addVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 1
model.addVertex({0.5f, 0.5f, -0.5f, 0.75f, 0.0f, 0.0f});   // 2
model.addVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 3
model.addVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.75f, 0.0f});  // 4
model.addVertex({-0.5f, 0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 5
model.addVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.75f, 0.0f});    // 6
model.addVertex({0.5f, -0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 7
model.addTriangle({4,0,7});
model.addTriangle({4,5,7});
model.addTriangle({4,5,0});
model.addTriangle({2,6,3});
model.addTriangle({2,6,1});
model.addTriangle({2,1,3});
model.addTriangle({5,0,7});
model.addTriangle({6,1,3});

model2.addVertex({1.0f, -1.0f, 0.0f});
model2.addVertex({1.0f, 1.0f, 0.0f});
model2.addVertex({3.0f, 1.0f, 0.0f});
model2.addVertex({3.0f, -1.0f, 0.0f});
model2.addTriangle({0, 1, 2});
model2.addTriangle({0, 2, 3});

model3.addVertex({-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f}); // 0
model3.addVertex({-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});  // 1
model3.addVertex({1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});   // 2
model3.addVertex({1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f});  // 3
model3.addTriangle({0,1,2});
model3.addTriangle({0,2,3});
*/