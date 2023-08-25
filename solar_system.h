//
// Created by imloul on 8/24/2023.
//

#ifndef SOLAR_SYSTEM_SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_SOLAR_SYSTEM_H


#include <vector>
#include "Drawable.h"
#include "Celestial.h"

class SolarSystem : public Drawable {
public:
    static const int MAX_PLANETS = 1'000'000;

    explicit SolarSystem(Celestial* star = nullptr);

    void addPlanet(Celestial* planet);
    void draw() override;
    void update(float dt);

    void setStar(Celestial* star);

private:
    Celestial* star;
    std::vector<Celestial*> planets;
};

#endif //SOLAR_SYSTEM_SOLAR_SYSTEM_H
