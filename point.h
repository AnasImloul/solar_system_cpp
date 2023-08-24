//
// Created by imloul on 8/23/2023.
//

#ifndef SOLAR_SYSTEM_POINT_H
#define SOLAR_SYSTEM_POINT_H

#include <GL/glut.h>


struct Point {
    GLfloat x;
    GLfloat y;

    Point(GLfloat x, GLfloat y);

    Point();

    Point operator+(const Point& other) const;

    Point operator-(const Point& other) const;

    Point operator*(const GLfloat& scalar) const;

    Point operator/(const GLfloat& scalar) const;

    Point& operator+=(const Point& other);

    Point& operator-=(const Point& other);

    Point& operator*=(const GLfloat& scalar);

    Point& operator/=(const GLfloat& scalar);

    bool operator==(const Point& other) const;

    bool operator!=(const Point& other) const;

    GLfloat magnitude() const;

    Point normalize() const;

    Point& normalizeSelf();

    GLfloat dot(const Point& other) const;

    GLfloat cross(const Point& other) const;

    Point project(const Point& other) const;

    Point reflect(const Point& normal) const;

    Point rotate(GLfloat angle) const;

    Point random();
};


#endif //SOLAR_SYSTEM_POINT_H
