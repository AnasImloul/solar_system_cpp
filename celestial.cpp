//
// Created by imloul on 8/23/2023.
//

#include "celestial.h"
#include "utils.h"
#include "constants.h"


Celestial::Celestial(Point& pos, GLfloat radius, GLfloat mass, Color& color, Point& velocity)
        : Particle(pos, radius, color, velocity),
          mass(mass){}

Point Celestial::gravity(Point& pos) {

    GLfloat dx = (pos.x - this->pos.x);
    GLfloat dy = (pos.y - this->pos.y);

    GLfloat distance = dx * dx + dy * dy;
    GLfloat inv = distance;

    GLfloat xhalf = 0.5f * inv;
    int i = *(int *) &inv;            // get bits for floating value
    i = 0x5f3759df - (i >> 1);        // gives initial guess y0
    inv = *(GLfloat *) &i;            // convert bits back to float
    inv = inv * (1.5f - xhalf * inv * inv);    // Newton step, repeating increases accuracy

    double constant = -G * this->mass / distance * inv;

    return {static_cast<GLfloat>(dx * constant), static_cast<GLfloat>(dy * constant)};
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

void Celestial::update(float dt) {
    Particle::update(dt);
}

Celestial::Celestial() : Particle() {}
