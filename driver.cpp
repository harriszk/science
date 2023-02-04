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

int main(int argc, char * argv[])
{
    
    FlyCamera camera(glm::vec3(0.0f, 0.0f, 30.0f), glm::vec3(10.0f, 5.0f, -5.0f));
    
    Display display(800, 600, "Hello World!");
    Shader shader("shaders/vertexShaderSource.glsl", "shaders/fragmentShaderSource.glsl");
    Renderer renderer(shader);
    FirstPersonController controller(&camera);
    display.setRenderer(&renderer);
    display.setContorller(&controller);
    Scene scene;
    scene.setCamera(&camera);
    renderer.addScene(&scene);

    Model model, model2, model3;
    
    scene.addModel(&model);
    scene.addModel(&model2);
    //scene.addModel(&model3);
    
    model.addVertex({-0.5f, -0.5f, -0.5f, 0.75f, 0.0f, 0.0f}); // 0
    model.addVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 1
    model.addVertex({0.5f, 0.5f, -0.5f, 0.75f, 0.0f, 0.0f});   // 2
    model.addVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 3
    model.addVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.75f, 0.0f});  // 4
    model.addVertex({-0.5f, 0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 5
    model.addVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.75f, 0.0f});    // 6
    model.addVertex({0.5f, -0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 7
    model.addTriangle({4,3,6});
    model.addTriangle({4,1,6});
    model.addTriangle({1,6,3});
    model.addTriangle({1,4,3});
    model.addTriangle({0,7,2});
    model.addTriangle({0,5,2});
    model.addTriangle({5,2,7});
    model.addTriangle({5,0,7});

    model2.addVertex({-1.0f, -1.0f, 0.0f});
    model2.addVertex({-1.0f, 1.0f, 0.0f});
    model2.addVertex({1.0f, 1.0f, 0.0f});
    model2.addVertex({1.0f, -1.0f, 0.0f});
    model2.addTriangle({0, 1, 2});
    model2.addTriangle({0, 2, 3});

    display.start();
    
    return 0;
} // end main

/*
    model.addVertex({-0.5f, -0.5f, -0.5f, 0.75f, 0.0f, 0.0f}); // 0
    model.addVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 1
    model.addVertex({0.5f, 0.5f, -0.5f, 0.75f, 0.0f, 0.0f});   // 2
    model.addVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 3
    model.addVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.75f, 0.0f});  // 4
    model.addVertex({-0.5f, 0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 5
    model.addVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.75f, 0.0f});    // 6
    model.addVertex({0.5f, -0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 7
    model.addTriangle({4,3,6});
    model.addTriangle({4,1,6});
    model.addTriangle({1,6,3});
    model.addTriangle({1,4,3});
    model.addTriangle({0,7,2});
    model.addTriangle({0,5,2});
    model.addTriangle({5,2,7});
    model.addTriangle({5,0,7});
    */
    /*
    model.addTriangle({4,0,7});
    model.addTriangle({4,5,7});
    model.addTriangle({4,5,0});
    model.addTriangle({2,6,3});
    model.addTriangle({2,6,1});
    model.addTriangle({2,1,3});
    model.addTriangle({5,0,7});
    model.addTriangle({6,1,3});
    */
    /*
    model.addTriangle({0, 1, 3});
    model.addTriangle({1, 3, 2});
    //model.addTriangle({0, 3, 2});
    //model.addTriangle({0, 2, 1});
    model.addTriangle({4, 5, 7});
    model.addTriangle({5, 6, 7});
    //model.addTriangle({4, 6, 7});
    //model.addTriangle({4, 5, 6});
    model.addTriangle({4, 0, 1});
    model.addTriangle({4, 1, 5});
    //model.addTriangle({0, 4, 5});
    //model.addTriangle({0, 5, 1});
    model.addTriangle({7, 3, 2});
    model.addTriangle({7, 2, 6});
    //model.addTriangle({3, 7, 6});
    //model.addTriangle({3, 6, 2});
    model.addTriangle({4, 0, 7});
    model.addTriangle({0, 3, 7});
    //model.addTriangle({4, 3, 7});
    //model.addTriangle({4, 3, 0});
    model.addTriangle({5, 1, 2});
    model.addTriangle({5, 2, 6});
    //model.addTriangle({6, 5, 1});
    //model.addTriangle({6, 1, 2});
    */