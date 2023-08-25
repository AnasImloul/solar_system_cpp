//
// Created by imloul on 8/23/2023.
//

#ifndef SOLAR_SYSTEM_UTILS_H
#define SOLAR_SYSTEM_UTILS_H

#include <GL/glut.h>
#include <chrono>

namespace utils {
    static const int64_t TIME_UNIT = 1'000'000'000;
    GLfloat random();
    GLfloat random(GLfloat min, GLfloat max);
    GLint randint(GLint min, GLint max);
    int64_t now();
    GLfloat invSqrt(GLfloat& x);
}

#endif //SOLAR_SYSTEM_UTILS_H
