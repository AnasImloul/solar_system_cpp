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

    void gravity(Celestial& other);

    Point perfectVelocity(Point& pos);

    bool operator<(const Celestial& other) const;

    bool operator>(const Celestial& other) const;

    GLfloat getMass() const ;

private:
    GLfloat mass;
};



#endif //SOLAR_SYSTEM_CELESTIAL_H
