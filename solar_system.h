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
    SolarSystem(Celestial* star = nullptr, const std::vector<Celestial*>& planets = {});

    void addPlanet(Celestial* planet);
    void draw() override;
    void update(float dt);

    void setStar(Celestial* star);

private:
    Celestial* star;
};

#endif //SOLAR_SYSTEM_SOLAR_SYSTEM_H
