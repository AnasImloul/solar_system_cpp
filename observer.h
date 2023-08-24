//
// Created by imloul on 8/23/2023.
//

#ifndef SOLAR_SYSTEM_OBSERVABLE_H
#define SOLAR_SYSTEM_OBSERVABLE_H


#include <vector>
#include <GL/glut.h>
#include "point.h"

class Observer {
public:
    virtual void updateObserver(Point& acceleration) = 0;
};

class Observable {
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    virtual void notifyObservers() = 0;

    std::vector<Observer*>::iterator begin();  // Define iterator begin
    std::vector<Observer*>::iterator end();    // Define iterator end

private:
    std::vector<Observer*> observers;

};


#endif //SOLAR_SYSTEM_OBSERVABLE_H
