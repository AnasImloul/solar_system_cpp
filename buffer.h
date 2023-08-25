//
// Created by imloul on 8/25/2023.
//

#ifndef SOLAR_SYSTEM_BUFFER_H
#define SOLAR_SYSTEM_BUFFER_H


#include <vector>

class Buffer {
public:
    static const int DEFAULT_SIZE = 100;

    Buffer(int size);
    void add(float value);
    float getSum() const;
    float getAverage() const;

private:
    int size;
    std::vector<float> buffer;
    int index;
    float sum;
};


#endif //SOLAR_SYSTEM_BUFFER_H
