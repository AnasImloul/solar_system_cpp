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
    planets.push_back(planet);
}

void SolarSystem::draw(GLuint win, const std::pair<float, float>& scale, const std::pair<int, int>& offset) {
    for (Celestial* planet : planets) {
        planet->draw();
    }

    star->draw();
}

void SolarSystem::update(float dt) {
    star->update(dt);
    for (Celestial* planet : planets) {
        planet->update(dt);
    }
}