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
    Drawable(Point& pos, GLfloat size, Color color);

    GLfloat getX() const;

    GLfloat getY() const;

    GLint getSize() const;

    Color getColor() const;

    void setX(GLfloat x);

    void setY(GLfloat y);

    void update(const Point& pos);

    void setSize(GLint size);

    void setColor(Color color);

    virtual void draw() = 0;


private:
    Point pos;
    GLint size;
    Color color;
};



#endif //SOLAR_SYSTEM_DRAWABLE_H