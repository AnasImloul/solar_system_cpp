//
// Created by imloul on 8/24/2023.
//

#ifndef SOLAR_SYSTEM_PARTICLE_H
#define SOLAR_SYSTEM_PARTICLE_H

#include "drawable.h"
#include "moveable.h"
#include "color.h"
#include "point.h"

#include <cmath>

class Particle: public Drawable, public Moveable {

public:
    Particle(Point& pos, GLfloat radius, Color& color, Point& velocity);

    Particle();

    void draw() override;

    Color getColor() const;


private:
    Color color;
    GLfloat radius;

};


#endif //SOLAR_SYSTEM_PARTICLE_H
