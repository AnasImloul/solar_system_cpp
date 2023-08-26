//
// Created by imloul on 8/24/2023.
//

#include "solar_system.h"
#include "utils.h"


SolarSystem::SolarSystem(Celestial* star)
        : Drawable() {
    if (star == nullptr) return;

    positions[0] = star->getX();
    positions[1] = star->getY();

    colors[0] = star->getColor().r;
    colors[1] = star->getColor().g;
    colors[2] = star->getColor().b;

    mass = star->getMass();

}

void SolarSystem::setStar(Celestial* star) {
    positions[0] = star->getX();
    positions[1] = star->getY();

    colors[0] = star->getColor().r;
    colors[1] = star->getColor().g;
    colors[2] = star->getColor().b;

    mass = star->getMass();
}


void SolarSystem::addPlanet(Celestial& planet) {
    if (planetCount == MAX_PLANETS) return;

    planetCount++;

    positions[planetCount * 2] = planet.getX();
    positions[planetCount * 2 + 1] = planet.getY();

    velocities[planetCount * 2] = planet.getVelocity().x;
    velocities[planetCount * 2 + 1] = planet.getVelocity().y;

    colors[planetCount * 3] = planet.getColor().r;
    colors[planetCount * 3 + 1] = planet.getColor().g;
    colors[planetCount * 3 + 2] = planet.getColor().b;
}

void SolarSystem::draw() {
    glEnableClientState(GL_VERTEX_ARRAY); // we are using VBAs : here's how to draw them
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(2,GL_FLOAT,0, positions) ;
    glColorPointer(3,GL_UNSIGNED_BYTE,0,colors) ;
    glDrawArrays(GL_POINTS,0,planetCount + 1) ;

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void SolarSystem::update(float dt) {

    int start, end;

    if (chunk < CHUNKS - 1) {
        start = (planetCount / CHUNKS) * chunk + 1;
        end = (planetCount / CHUNKS) * (chunk + 1) + 1;
    } else {
        start = (planetCount / CHUNKS) * chunk + 1;
        end = planetCount + 1;
    }

    for (int index = start; index < end; index++) {

        // calculate gravity
        GLfloat dx = (positions[2 * index] - positions[0]);
        GLfloat dy = (positions[2 * index + 1] - positions[1]);

        GLfloat distance = dx * dx + dy * dy;

        GLfloat constant = -utils::G * mass / distance * utils::invSqrt(distance);

        accelerations[2 * index] = dx * constant;
        accelerations[2 * index + 1] = dy * constant;
    }


    // update position and velocity
    for (int index = 1; index < planetCount + 1; index++) {

        positions[2 * index] += velocities[2 * index] * dt;
        positions[2 * index + 1] += velocities[2 * index + 1] * dt;

        velocities[2 * index] += accelerations[2 * index] * dt;
        velocities[2 * index + 1] += accelerations[2 * index + 1] * dt;
    }

    chunk = (chunk + 1) % CHUNKS;
}
