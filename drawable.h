//
// Created by imloul on 8/23/2023.
//

#ifndef SOLAR_SYSTEM_DRAWABLE_H
#define SOLAR_SYSTEM_DRAWABLE_H


#include <iostream>
#include <GL/freeglut.h> // Assuming you're using GLUT for OpenGL
#include <utility>
#include "color.h"
#include "point.h"

class Drawable {
public:
    Drawable();

    virtual void draw() = 0;

};



#endif //SOLAR_SYSTEM_DRAWABLE_H