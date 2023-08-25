//
// Created by imloul on 8/23/2023.
//

#include "celestial.h"
#include "utils.h"
#include "constants.h"


Celestial::Celestial(Point& pos, GLfloat radius, GLfloat mass, Color& color, Point& velocity)
        : Particle(pos, radius, color, velocity),
          mass(mass){}

void Celestial::gravity(Celestial& other) {

    GLfloat dx = (other.pos.x - pos.x);
    GLfloat dy = (other.pos.y - pos.y);

    GLfloat distance = dx * dx + dy * dy;

    double constant = -G * this->mass / distance * utils::invSqrt(distance);

    other.acceleration.x += dx * constant;
    other.acceleration.y += dy * constant;
}

Point Celestial::perfectVelocity(Point& pos) {

    GLfloat dx = (pos.x - this->pos.x);
    GLfloat dy = (pos.y - this->pos.y);

    GLfloat distance = std::sqrt(dx * dx + dy * dy);

    dx = dx / distance;
    dy = dy / distance;

    double constant = -std::sqrt(G * mass / distance);

    return Point(-dy * constant, dx * constant);
}


bool Celestial::operator<(const Celestial& other) const {
    return false;
}

bool Celestial::operator>(const Celestial& other) const {
    return false;
}


Celestial::Celestial() : Particle() {}
