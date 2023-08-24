//
// Created by imloul on 8/24/2023.
//

#include "solar_system.h"

SolarSystem::SolarSystem(Celestial* star, const std::vector<Celestial*>& planets)
        : Drawable(), star(star) {
    if (star != nullptr) {
        this->star = star;
    }

    for (Celestial* planet : planets) {
        addPlanet(planet);
    }
}

void SolarSystem::addPlanet(Celestial* planet) {
    if (planet != nullptr) {
        planets.push_back(planet);
    }
}

void SolarSystem::draw() {
    for (Celestial* planet : planets) {
        planet->draw();
    }
    star->draw();
}

void SolarSystem::update(float dt) {
    star->update(dt);
    Point acc, pos;
    for (Celestial* planet : planets) {
        pos = planet->getPosition();
        acc = star->gravity(pos);
        planet->accelerate(acc);
        planet->update(dt);
    }
}

void SolarSystem::setStar(Celestial *star) {
    this->star = star;
}
