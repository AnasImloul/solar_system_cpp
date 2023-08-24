//
// Created by imloul on 8/23/2023.
//

#include "observer.h"
#include <algorithm>


void Observable::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Observable::removeObserver(Observer* observer) {
    // Find and remove the observer from the vector
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) {
        observers.erase(it);
    }
}

std::vector<Observer*>::iterator Observable::begin() {
    return observers.begin();
}

std::vector<Observer*>::iterator Observable::end() {
    return observers.end();
}

