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
    static const int MAX_PLANETS = 100'000;

    explicit SolarSystem(Celestial* star = nullptr);

    void addPlanet(Celestial& planet);
    void draw() override;
    void update(float dt);

    void setStar(Celestial* star);

private:
    Celestial* star;
    Celestial planets[MAX_PLANETS];
    int planetCount = 0;
    GLfloat positions[MAX_PLANETS * 2];
    char colors[MAX_PLANETS * 3];

};

#endif //SOLAR_SYSTEM_SOLAR_SYSTEM_H
