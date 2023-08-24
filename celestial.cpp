//
// Created by imloul on 8/23/2023.
//

#include "celestial.h"

#include "celestial.h"
#include "constants.h"
#include <algorithm> // For std::min

Celestial::Celestial(Point& pos, GLfloat radius, GLfloat mass, Color& color, Point& velocity)
        : Particle(pos, radius, color, velocity),
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
    Particle::update(dt);
    notifyObservers();
}
