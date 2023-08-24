//
// Created by imloul on 8/24/2023.
//

#include "particle.h"


Particle::Particle(Point &pos, GLfloat radius, Color &color, Point &velocity)
        : Drawable(pos, radius, color),
          Moveable(pos, velocity),
          radius(radius) {}



void Particle::draw() {
    Color color = Drawable::getColor();
    glColor3f(color.r, color.g, color.b);
    glPointSize(radius);
    glBegin(GL_POINTS);
    glVertex2f(Drawable::getX(), Drawable::getY());
    glEnd();
}

void Particle::update(float dt) {
    move(dt);
    Drawable::update(getPosition());
}