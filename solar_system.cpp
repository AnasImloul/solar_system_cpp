//
// Created by imloul on 8/24/2023.
//

#include "solar_system.h"

SolarSystem::SolarSystem(Celestial* star)
        : Drawable(), star(star) {
    if (star != nullptr) {
        this->star = star;
    }

}

void SolarSystem::addPlanet(Celestial& planet) {
    planets[planetCount++] = planet;
}

void SolarSystem::draw() {
    glEnableClientState(GL_VERTEX_ARRAY); // we are using VBAs : here's how to draw them
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2,GL_FLOAT,0, positions) ;
    glColorPointer(3,GL_UNSIGNED_BYTE,0,colors) ;
    glDrawArrays(GL_POINTS,0,MAX_PLANETS) ;


    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

}

void SolarSystem::update(float dt) {
    star->move(dt);

    positions[0] = star->getX();
    positions[1] = star->getY();

    colors[0] = star->getColor().r;
    colors[1] = star->getColor().g;
    colors[2] = star->getColor().b;

    Color color;
    for (int i = 1; i < planetCount + 1; i++) {
        star->gravity(planets[i - 1]);

        planets[i - 1].move(dt);

        positions[i * 2] = planets[i - 1].getX();
        positions[i * 2 + 1] = planets[i - 1].getY();

        color = planets[i - 1].getColor();
        colors[i * 3] = color.r;
        colors[i * 3 + 1] = color.g;
        colors[i * 3 + 2] = color.b;
    }
}

void SolarSystem::setStar(Celestial* star) {
    this->star = star;
}
