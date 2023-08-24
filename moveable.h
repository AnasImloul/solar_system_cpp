//
// Created by imloul on 8/23/2023.
//

#include <utility>
#include <GL/glut.h>
#include "point.h"


#ifndef SOLAR_SYSTEM_MOVEABLE_H
#define SOLAR_SYSTEM_MOVEABLE_H


class Moveable {
public:
    Moveable(Point& pos, Point& velocity);

    void move(float dt);
    void accelerate(Point& acceleration);
    void setVelocity(Point& velocity);

    const Point& getPosition() const;
    const Point& getVelocity() const;


private:
    Point pos;
    Point velocity;
    Point acceleration;
};


#endif //SOLAR_SYSTEM_MOVEABLE_H
