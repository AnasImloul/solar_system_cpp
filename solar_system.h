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
    static const int CHUNKS = 2;

    explicit SolarSystem(Celestial* star = nullptr);

    void addPlanet(Celestial& planet);
    void draw() override;
    void update(float dt);

    void setStar(Celestial* star);


private:
    int planetCount = 0;
    GLfloat positions[(MAX_PLANETS + 1) * 2];
    GLfloat velocities[(MAX_PLANETS + 1) * 2];
    GLfloat accelerations[(MAX_PLANETS + 1) * 2];
    char colors[(MAX_PLANETS + 1) * 3];
    GLfloat mass;
    int chunk = 0;

};

#endif //SOLAR_SYSTEM_SOLAR_SYSTEM_H
