/**
 * @file Display.h
 * Created on 01/16/2023
 * 
 * 
 * 
 * © 2023 by Zachary Harris (zacharykeatonharris@gmail.com)
 */
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdlib.h>

class Display {
    public:
        Display(int width, int height);

        ~Display();

    private:
        size_t width;

        size_t height;
}; // end Display class

#endif