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
    star->addOrbiter(planet);
}

void SolarSystem::draw() {
    for (Observer* planet : *star) {
        dynamic_cast<Celestial*>(planet)->draw();
    }
    star->draw();
}

void SolarSystem::update(float dt) {
    star->update(dt);;
    for (Observer* planet : *star) {
        dynamic_cast<Celestial*>(planet)->update(dt);
    }
}

void SolarSystem::setStar(Celestial *star) {
    this->star = star;
}
