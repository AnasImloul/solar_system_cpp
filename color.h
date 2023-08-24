//
// Created by imloul on 8/23/2023.
//

#ifndef SOLAR_SYSTEM_COLOR_H
#define SOLAR_SYSTEM_COLOR_H

#include <GL/glut.h>


struct Color {
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;

    Color(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    Color(GLfloat r, GLfloat g, GLfloat b);

    Color();

    Color operator+(const Color& other) const;

    Color operator-(const Color& other) const;

    Color operator*(const GLfloat& scalar);

    Color operator/(const GLfloat& scalar);

    Color& operator+=(const Color& other);

    Color& operator-=(const Color& other);

    Color& operator*=(const GLfloat& scalar);

    Color& operator/=(const GLfloat& scalar);

    bool operator==(const Color& other);

    bool operator!=(const Color& other);

    static Color random();

    static Color random(GLfloat alpha);

    static Color random(GLfloat min, GLfloat max);

    static Color random(GLfloat min, GLfloat max, GLfloat alpha);

    static Color random(Color min, Color max);
};


#endif //SOLAR_SYSTEM_COLOR_H
