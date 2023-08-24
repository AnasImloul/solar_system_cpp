//
// Created by imloul on 8/23/2023.
//

#include "celestial.h"
#include "utils.h"
#include "constants.h"


Celestial::Celestial(Point& pos, GLfloat radius, GLfloat mass, Color& color, Point& velocity)
        : Particle(pos, radius, color, velocity),
          Observable(),
          Observer(),
          mass(mass),
          radius(radius) {}

Point Celestial::gravity(Point& pos) {

    GLfloat dx = (pos.x - this->pos.x);
    GLfloat dy = (pos.y - this->pos.y);

    GLfloat distance = dx * dx + dy * dy;
    GLfloat inv = distance;


    double constant = -G * this->mass / distance * utils::invSqrt(distance);

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



void Celestial::addOrbiter(Celestial *planet) {
    addObserver(static_cast<Observer*>(planet));
}

void Celestial::notifyObservers() {
    for (auto* observer : *this) {
        Point pos = dynamic_cast<Particle*>(observer)->getPosition();
        Point acceleration = gravity(pos);
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
    Observable::update();
}
