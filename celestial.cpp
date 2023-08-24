//
// Created by imloul on 8/23/2023.
//

#include "celestial.h"

#include "celestial.h"
#include "constants.h"
#include <algorithm> // For std::min

Celestial::Celestial(Point& pos, GLfloat radius, GLfloat mass, Color& color, Point& velocity)
        : Drawable(pos, radius, color),
          Moveable(pos, velocity),
          Observable(),
          Observer(),
          mass(mass),
          radius(radius) {}

Point Celestial::gravity(const Celestial& other) {
    Point myPos = getPosition();
    Point otherPos = other.getPosition();

    Point deltaPos = otherPos - myPos;
    double distance = deltaPos.magnitude();

    if (distance < radius + other.radius) {
        return Point(0, 0);
    }

    deltaPos.normalize();

    GLfloat constant = -G * mass / (distance * distance);

    return deltaPos * constant;
}

Point Celestial::perfectVelocity(const Celestial& planet) {
    Point myPos = getPosition();
    Point planetPos = planet.getPosition();

    Point deltaPos = myPos - planetPos;
    double distance = deltaPos.magnitude();

    deltaPos.normalize();

    double constant = -std::sqrt(G * mass / distance);

    return deltaPos * constant;
}


void Celestial::addOrbiter(Celestial& planet) {
    addObserver(static_cast<Observer*>(&planet));
}

void Celestial::notifyObservers() {
    for (auto* observer : *this) {
        Point acceleration = gravity(*dynamic_cast<Celestial*>(observer));
        observer->updateObserver(acceleration);
    }
}

void Celestial::updateObserver(Point &acceleration) {
    accelerate(acceleration);
}

void Celestial::draw() {
    glPushMatrix();
    glTranslatef(getX(), getY(), 0);
    glColor3f(getColor().r, getColor().g, getColor().b);

    const float halfSize = getSize() / 2.0f;
    glBegin(GL_QUADS);
    glVertex2f(-halfSize, -halfSize); // Bottom-left
    glVertex2f(halfSize, -halfSize);  // Bottom-right
    glVertex2f(halfSize, halfSize);   // Top-right
    glVertex2f(-halfSize, halfSize);  // Top-left
    glEnd();

    glPopMatrix();
}

void Celestial::removePlanet(Celestial& planet) {
    removeObserver(static_cast<Observer*>(&planet));
}

bool Celestial::operator<(const Celestial& other) const {
    return false;
}

bool Celestial::operator>(const Celestial& other) const {
    return false;
}

void Celestial::update(float dt) {
    move(dt);
    notifyObservers();
    Drawable::update(getPosition());
}
