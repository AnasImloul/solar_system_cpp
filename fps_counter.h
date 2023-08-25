//
// Created by imloul on 8/25/2023.
//

#ifndef SOLAR_SYSTEM_FPS_COUNTER_H
#define SOLAR_SYSTEM_FPS_COUNTER_H

#include "drawable.h"
#include "buffer.h"
#include "point.h"
#include "color.h"



class FPSCounter {
public:
    FPSCounter(int refreshRate = 1000);

    void update();
    GLfloat getFPS() const;

private:
    int refreshRate;
    uint64_t lastUpdate;
    Buffer fpsBuffer;
};

#endif //SOLAR_SYSTEM_FPS_COUNTER_H
