//
// Created by imloul on 8/23/2023.
//

#include "utils.h"


GLfloat utils::random() {
    return (GLfloat) rand() / RAND_MAX;
}

GLfloat utils::random(GLfloat min, GLfloat max) {
    return min + random() * (max - min);
}

GLint utils::randint(GLint min, GLint max) {
    return min + rand() % (max - min + 1);
}

int64_t utils::now() {
    using namespace std::chrono;
    return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
}

GLfloat utils::invSqrt(GLfloat& x) {
    // GLfloat xhalf = 0.5f * x;
    int i = *(int *) &x;            // get bits for floating value
    i = 0x5f3759df - (i >> 1);        // gives initial guess y0
    x = *(GLfloat *) &i;            // convert bits back to float
    // x = x * (1.5f - xhalf * x * x);    // Newton step, repeating increases accuracy
    return x;
}