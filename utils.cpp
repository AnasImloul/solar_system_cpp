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

int64_t utils::now() {
    using namespace std::chrono;
    return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
}