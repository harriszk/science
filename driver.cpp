#include "Display.h"
#include "Renderer.h"
#include "Model.h"

int main(int argc, char * argv[])
{
    Display display(800, 600, "Hello World!");
    Shader shader("shaders/vertexShaderSource.glsl", "shaders/fragmentShaderSource.glsl");
    Renderer renderer(display, shader);
    display.setTitle("New Title!");

    renderer.startRendering();

    return 0;
} // end main