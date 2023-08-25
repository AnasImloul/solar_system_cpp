//
// Created by imloul on 8/25/2023.
//

#include "buffer.h"

Buffer::Buffer(int size)
        : size(size), buffer(size, 0), index(0), sum(0) {}

void Buffer::add(float value) {
    if (index < size) {
        sum += value;
    } else {
        sum += value;
        sum -= buffer[index % size];
    }

    buffer[index % size] = value;
    index += 1;
}

float Buffer::getSum() const {
    return sum;
}

float Buffer::getAverage() const {
    if (index == 0) {
        return 0;
    } else if (index < size) {
        return sum / index;
    } else {
        return sum / size;
    }
}