//
// Created by imloul on 8/23/2023.
//

#ifndef SOLAR_SYSTEM_UTILS_H
#define SOLAR_SYSTEM_UTILS_H

#include <GL/glut.h>
#include <chrono>

namespace utils {
    GLfloat random();
    GLfloat random(GLfloat min, GLfloat max);
    int64_t now();
}

#endif //SOLAR_SYSTEM_UTILS_H
