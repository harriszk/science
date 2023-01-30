#include "Display.h"
#include "Renderer.h"

int main(int argc, char * argv[])
{
    Display display(800, 600, "Hello World!");
    Renderer renderer(display);

    renderer.startRendering();

    return 0;
} // end main