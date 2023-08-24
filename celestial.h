//
// Created by imloul on 8/23/2023.
//

#ifndef SOLAR_SYSTEM_CELESTIAL_H
#define SOLAR_SYSTEM_CELESTIAL_H


#ifndef CELESTIAL_H
#define CELESTIAL_H

#include "GL/glut.h"

#include "drawable.h"
#include "observer.h"
#include "moveable.h"
#include "color.h"
#include "point.h"

#include <cmath>

class Celestial : public Drawable, public Observable, public Observer, public Moveable {
public:
    Celestial(Point& pos, GLfloat radius, GLfloat mass, Color& color, Point& velocity);

    Point gravity(const Celestial& other);

    Point perfectVelocity(const Celestial& planet);

    void draw() override;

    void updateObserver(Point& acceleration) override;

    void notifyObservers() override;

    void update(float dt);

    void addOrbiter(Celestial& planet);

    void removePlanet(Celestial& planet);

    bool operator<(const Celestial& other) const;

    bool operator>(const Celestial& other) const;

private:
    double mass;
    double radius;
};

#endif // CELESTIAL_H



#endif //SOLAR_SYSTEM_CELESTIAL_H
