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
    void draw(GLuint win, const std::pair<float, float>& scale, const std::pair<int, int>& offset);
    void update(float dt);


private:
    Celestial* star;
    std::vector<Celestial*> planets;
};

#endif //SOLAR_SYSTEM_SOLAR_SYSTEM_H
