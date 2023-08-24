//
// Created by imloul on 8/24/2023.
//

#ifndef SOLAR_SYSTEM_PARTICLE_H
#define SOLAR_SYSTEM_PARTICLE_H

#include "drawable.h"
#include "observer.h"
#include "moveable.h"
#include "color.h"
#include "point.h"

#include <cmath>

class Particle: public Drawable, public Moveable {

public:
    Particle(Point& pos, GLfloat radius, Color& color, Point& velocity);

    void draw() override;

    virtual void update(float dt);


private:
    double radius;
};


#endif //SOLAR_SYSTEM_PARTICLE_H
