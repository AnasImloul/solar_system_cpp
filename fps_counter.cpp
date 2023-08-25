//
// Created by imloul on 8/25/2023.
//

#include "fps_counter.h"
#include "utils.h"


FPSCounter::FPSCounter(int refreshRate): refreshRate(refreshRate), lastUpdate(0), fpsBuffer(Buffer::DEFAULT_SIZE) {
}

void FPSCounter::update() {
    uint64_t now = utils::now();
    GLfloat fps = 1'000'000.f / (now - lastUpdate);

    fpsBuffer.add(fps);

    if (lastUpdate == 0) {
        lastUpdate = utils::now();
    } else if (utils::now() - lastUpdate > refreshRate / 1000) {
        lastUpdate = utils::now();
    }
}

GLfloat FPSCounter::getFPS() const {
    return fpsBuffer.getAverage();
}