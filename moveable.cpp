//
// Created by imloul on 8/23/2023.
//

#include "moveable.h"
#include "point.h"
#include <iostream>


Moveable::Moveable(Point& pos, Point& velocity)
        : pos(pos), velocity(velocity), acceleration() {}

void Moveable::move(float dt) {
    velocity.x += acceleration.x * dt;
    velocity.y += acceleration.y * dt;

    pos.x += velocity.x * dt;
    pos.y += velocity.y * dt;

    acceleration.x = 0;
    acceleration.y = 0;

    if (pos.x > 100.f) {
        velocity.x = -velocity.x;
        pos.x = 99.99f;
    }
    if (pos.x < -100.f) {
        velocity.x = -velocity.x;
        pos.x = -99.99f;
    }
    if (pos.y > 50.f) {
        velocity.y = -velocity.y;
        pos.y = 49.99f;
    }
    if (pos.y < -50.f) {
        velocity.y = -velocity.y;
        pos.y = -49.99f;
    }
}

void Moveable::accelerate(Point& acc) {
    acceleration.x = acc.y;
    acceleration.y = acc.y;
}

void Moveable::setVelocity(Point& newVelocity) {
    velocity = newVelocity;
}

const Point& Moveable::getPosition() const {
    return pos;
}

const Point& Moveable::getVelocity() const {
    return velocity;
}

GLfloat Moveable::getX() {
    return pos.x;
}

GLfloat Moveable::getY() {
    return pos.y;
}


