#include "Vector.h"
#include <iostream>

int main(int argc, char * argv[])
{
    Vector<3> u;
    u[0] = 4;
    u[1] = 7;
    u[2] = 1;

    float s = 4.0;

    s * u;

    for(int i = 0; i < 3; i++)
    {
        std::cout << u[i] << " ";
    }
    
    Vector<3> v;
    v[0] = 7;
    v[1] = 1;
    v[2] = 4;

    std::cout << u * v << std::endl;
    std::cout << v * u << std::endl;

    return 0;
}