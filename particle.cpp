//
// Created by imloul on 8/24/2023.
//

#include "particle.h"


Particle::Particle(Point &pos, GLfloat radius, Color &color, Point &velocity)
        : Drawable(),
          Moveable(pos, velocity),
          radius(radius),
          color(color)
          {}


void Particle::draw() {
    glColor3f(color.r, color.g, color.b);
    glPointSize(radius);
    glBegin(GL_POINTS);
    glVertex2f(pos.x, pos.y);
    glEnd();
}

void Particle::update(float dt) {
    move(dt);
}