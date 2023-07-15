#include "render/display.h"
#include "render/renderer.h"
#include "render/scene.h"
#include "render/model.h"
#include "render/shader.h"
#include "render/vertex_array_object.h"
#include "render/vertex_buffer_object.h"
#include "render/element_buffer_object.h"
#include "render/vertex.h"
#include "render/triangle.h"
#include <vector>

#include "render/first_person_controller.h"
#include "render/fly_camera.h"
#include "render/camera_2d.h"
#include "render/controller_2d.h"
#include "render/rectangle.h"
#include "render/circle.h"
#include "render/line.h"
#include "render/coordinate_system_2d.h"

#include "rapidjson/document.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <iostream>

#include "physics/periodic_table.h"
#include "physics/particle.h"

#include "render/third-parties/include/imgui/imgui.h"
#include "render/third-parties/include/imgui/imgui_impl_glfw.h"
#include "render/third-parties/include/imgui/imgui_impl_opengl3.h"

int main(int argc, char * argv[])
{
    //FlyCamera camera(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f));



    Camera2D camera;
    Controller2D controller(&camera);
    //FirstPersonController controller(&camera);

    Display display(950, 800, "Hello World!");
    Shader shader("../src/render/shaders/vertexShaderSource.glsl", "../src/render/shaders/fragmentShaderSource.glsl");
    Renderer renderer(shader);
    display.set_renderer(&renderer);
    display.set_controller(&controller);
    Scene scene;
    scene.set_camera(&camera);
    renderer.AddScene(&scene);

    //Model model;
    //scene.AddRenderable(&model);
    //model.loadModel("../src/render/models/teapot.obj");
    /*
    model.AddVertex({-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f}); // 0
    model.AddVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f});  // 1
    model.AddVertex({0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f});   // 2
    model.AddVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f});  // 3
    model.AddVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f});  // 4
    model.AddVertex({-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f});   // 5
    model.AddVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f});    // 6
    model.AddVertex({0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f});   // 7
    model.AddTriangle({0,1,2});
    model.AddTriangle({0,2,3});
    model.AddTriangle({0,1,5});
    model.AddTriangle({0,5,4});
    model.AddTriangle({1,2,6});
    model.AddTriangle({1,6,5});
    model.AddTriangle({3,2,6});
    model.AddTriangle({3,6,7});
    model.AddTriangle({0,3,7});
    model.AddTriangle({0,7,4});
    model.AddTriangle({5,6,7});
    model.AddTriangle({5,7,4});


    CoordinateSystem2D cs(-5, 5, -5, 5);
    scene.AddRenderable(&cs);

    Rectangle rect(1.5f, 1.25f);
    scene.AddRenderable(&rect);

    //Circle circle(2.5f);
    //scene.AddRenderable(&circle);

    // Use either a start method or have which ever component is using
    // the display update it.
    //display.start();

    glEnable(GL_DEPTH_TEST);

    float lastFrame, dt;

    while(!display.shouldClose())
    {
    float currentFrame = static_cast<float>(glfwGetTime());
    dt = currentFrame - lastFrame;
    lastFrame = currentFrame;

    //rect.setRotation((30.0f * dt) + rect.getRotation());

    display.paintFrame();
    } // end while

    return 0;
    */
    
    Model model, model2, model3;

    scene.AddRenderable(&model);
    scene.AddRenderable(&model2);
    scene.AddRenderable(&model3);

    model.AddVertex({-0.5f, -0.5f, -0.5f, 0.75f, 0.0f, 0.0f}); // 0
    model.AddVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 1
    model.AddVertex({0.5f, 0.5f, -0.5f, 0.75f, 0.0f, 0.0f});   // 2
    model.AddVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 3
    model.AddVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.75f, 0.0f});  // 4
    model.AddVertex({-0.5f, 0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 5
    model.AddVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.75f, 0.0f});    // 6
    model.AddVertex({0.5f, -0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 7
    model.AddTriangle({4,0,7});
    model.AddTriangle({4,5,7});
    model.AddTriangle({4,5,0});
    model.AddTriangle({2,6,3});
    model.AddTriangle({2,6,1});
    model.AddTriangle({2,1,3});
    model.AddTriangle({5,0,7});
    model.AddTriangle({6,1,3});

    model2.AddVertex({1.0f, -1.0f, 0.0f});
    model2.AddVertex({1.0f, 1.0f, 0.0f});
    model2.AddVertex({3.0f, 1.0f, 0.0f});
    model2.AddVertex({3.0f, -1.0f, 0.0f});
    model2.AddTriangle({0, 1, 2});
    model2.AddTriangle({0, 2, 3});

    model3.AddVertex({-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f}); // 0
    model3.AddVertex({-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});  // 1
    model3.AddVertex({1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});   // 2
    model3.AddVertex({1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f});  // 3
    model3.AddTriangle({0,1,2});
    model3.AddTriangle({0,2,3});

    //display.start();
    
    
    while(!display.ShouldClose())
    {
        display.PaintFrame();
    } // end while

    return 0;
} // end main

// ------------------ RENDER ENGINE TESTING ------------------

/*
//FlyCamera camera(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
//FirstPersonController controller(&camera);

Camera2D camera;
Controller2D controller(&camera);

Display display(1000, 1000, "Hello World!");
Shader shader("../src/render/shaders/vertexShaderSource.glsl", "../src/render/shaders/fragmentShaderSource.glsl");
Renderer renderer(shader);
display.setRenderer(&renderer);
display.setContorller(&controller);
Scene scene;
scene.setCamera(&camera);
renderer.addScene(&scene);

//Model model;
//scene.AddRenderable(&model);
//model.loadModel("../src/render/models/teapot.obj");
/*
model.AddVertex({-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f}); // 0
model.AddVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f});  // 1
model.AddVertex({0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f});   // 2
model.AddVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f});  // 3
model.AddVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f});  // 4
model.AddVertex({-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f});   // 5
model.AddVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f});    // 6
model.AddVertex({0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f});   // 7
model.AddTriangle({0,1,2});
model.AddTriangle({0,2,3});
model.AddTriangle({0,1,5});
model.AddTriangle({0,5,4});
model.AddTriangle({1,2,6});
model.AddTriangle({1,6,5});
model.AddTriangle({3,2,6});
model.AddTriangle({3,6,7});
model.AddTriangle({0,3,7});
model.AddTriangle({0,7,4});
model.AddTriangle({5,6,7});
model.AddTriangle({5,7,4});


CoordinateSystem2D cs(-5, 5, -5, 5);
scene.AddRenderable(&cs);

Rectangle rect(1.5f, 1.25f);
scene.AddRenderable(&rect);

//Circle circle(2.5f);
//scene.AddRenderable(&circle);

// Use either a start method or have which ever component is using
// the display update it.
//display.start();

glEnable(GL_DEPTH_TEST);

float lastFrame, dt;

while(!display.shouldClose())
{
    float currentFrame = static_cast<float>(glfwGetTime());
    dt = currentFrame - lastFrame;
    lastFrame = currentFrame;

    //rect.setRotation((30.0f * dt) + rect.getRotation());

    display.paintFrame();
} // end while

return 0;
*/

/*
Model model, model2, model3;

scene.AddRenderable(&model);
scene.AddRenderable(&model2);
scene.AddRenderable(&model3);

model.AddVertex({-0.5f, -0.5f, -0.5f, 0.75f, 0.0f, 0.0f}); // 0
model.AddVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 1
model.AddVertex({0.5f, 0.5f, -0.5f, 0.75f, 0.0f, 0.0f});   // 2
model.AddVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.75f, 0.0f});  // 3
model.AddVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.75f, 0.0f});  // 4
model.AddVertex({-0.5f, 0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 5
model.AddVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.75f, 0.0f});    // 6
model.AddVertex({0.5f, -0.5f, 0.5f, 0.75f, 0.0f, 0.0f});   // 7
model.AddTriangle({4,0,7});
model.AddTriangle({4,5,7});
model.AddTriangle({4,5,0});
model.AddTriangle({2,6,3});
model.AddTriangle({2,6,1});
model.AddTriangle({2,1,3});
model.AddTriangle({5,0,7});
model.AddTriangle({6,1,3});

model2.AddVertex({1.0f, -1.0f, 0.0f});
model2.AddVertex({1.0f, 1.0f, 0.0f});
model2.AddVertex({3.0f, 1.0f, 0.0f});
model2.AddVertex({3.0f, -1.0f, 0.0f});
model2.AddTriangle({0, 1, 2});
model2.AddTriangle({0, 2, 3});

model3.AddVertex({-1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f}); // 0
model3.AddVertex({-1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});  // 1
model3.AddVertex({1.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f});   // 2
model3.AddVertex({1.0f, -1.0f, 0.0f, 1.0f, 1.0f, 1.0f});  // 3
model3.AddTriangle({0,1,2});
model3.AddTriangle({0,2,3});
*/