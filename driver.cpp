#include "include/render/Display.h"
#include "include/render/Renderer.h"
#include "include/render/Scene.h"
#include "include/render/Model.h"
#include "include/render/Shader.h"
#include "include/render/VertexArrayObject.h"
#include "include/render/VertexBufferObject.h"
#include "include/render/ElementBufferObject.h"
#include "include/render/Vertex.h"
#include "include/render/Triangle.h"
#include <vector>

#include "include/render/FirstPersonController.h"
#include "include/render/FlyCamera.h"
#include "include/render/Camera2D.h"
#include "include/render/Controller2D.h"
#include "include/render/Rectangle.h"
#include "include/render/Circle.h"
#include "include/render/Line.h"
#include "include/render/CoordinateSystem2D.h"

#include "rapidjson/document.h"
//#include "rapidjson/writer.h"
//#include "rapidjson/stringbuffer.h"
#include "rapidjson/filereadstream.h"
#include <cstdio>
#include <iostream>

#include "include/physics/PeriodicTable.h"

int main(int argc, char * argv[])
{
    /*
    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":20}";
    rapidjson::Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    rapidjson::Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    */

    /*
    const char json[] = "{ \"hello\" : \"world\" }";
    rapidjson::StringStream s(json);
    
    rapidjson::Document d;
    d.ParseStream(s);

    std::cout << d["hello"].GetString() << "\n";
    */

    PeriodicTable& periodicTable = PeriodicTable::getInstance();

    for(int i = 1; i < 119; i++)
    {
        periodicTable.getElement(i);
    }
    

    return 0;

} // end main

// ------------------ RENDER ENGINE TESTING ------------------

/*
//FlyCamera camera(glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
//FirstPersonController controller(&camera);

Camera2D camera;
Controller2D controller(&camera);

Display display(1000, 1000, "Hello World!");
Shader shader("/Users/zachary/Desktop/Science/src/render/shaders/vertexShaderSource.glsl", "/Users/zachary/Desktop/Science/src/render/shaders/fragmentShaderSource.glsl");
Renderer renderer(shader);
display.setRenderer(&renderer);
display.setContorller(&controller);
Scene scene;
scene.setCamera(&camera);
renderer.addScene(&scene);

//Model model;
//scene.addRenderable(&model);
//model.loadModel("/Users/zachary/Desktop/Science/src/render/models/teapot.obj");
/*
model.addVertex({-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f}); // 0
model.addVertex({-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f});  // 1
model.addVertex({0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f});   // 2
model.addVertex({0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f});  // 3
model.addVertex({-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f});  // 4
model.addVertex({-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f});   // 5
model.addVertex({0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f});    // 6
model.addVertex({0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f});   // 7
model.addTriangle({0,1,2});
model.addTriangle({0,2,3});
model.addTriangle({0,1,5});
model.addTriangle({0,5,4});
model.addTriangle({1,2,6});
model.addTriangle({1,6,5});
model.addTriangle({3,2,6});
model.addTriangle({3,6,7});
model.addTriangle({0,3,7});
model.addTriangle({0,7,4});
model.addTriangle({5,6,7});
model.addTriangle({5,7,4});


CoordinateSystem2D cs(-5, 5, -5, 5);
scene.addRenderable(&cs);

Rectangle rect(1.5f, 1.25f);
scene.addRenderable(&rect);

//Circle circle(2.5f);
//scene.addRenderable(&circle);

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