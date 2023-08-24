//
// Created by imloul on 8/23/2023.
//

#ifndef SOLAR_SYSTEM_CELESTIAL_H
#define SOLAR_SYSTEM_CELESTIAL_H


#include "GL/glut.h"

#include "particle.h"
#include "color.h"
#include "point.h"

#include <cmath>

class Celestial : public Particle {
public:
    Celestial(Point& pos, GLfloat radius, GLfloat mass, Color& color, Point& velocity);

    Celestial();

    Point gravity(Point& pos);

    Point perfectVelocity(Point& pos);

    void update(float dt) override;

    bool operator<(const Celestial& other) const;

    bool operator>(const Celestial& other) const;


private:
    GLfloat mass;
};



#endif //SOLAR_SYSTEM_CELESTIAL_H
