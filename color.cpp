//
// Created by imloul on 8/23/2023.
//

#include "color.h"
#include "utils.h"


Color::Color(GLfloat r, GLfloat g, GLfloat b): r(r), g(g), b(b) {}

Color::Color(): r(0), g(0), b(0) {}

Color Color::operator+(const Color &other) const {
    return {r + other.r, g + other.g, b + other.b};
}

Color Color::operator-(const Color &other) const {
    return {r - other.r, g - other.g, b - other.b};
}

Color Color::operator*(const GLfloat &scalar) {
    return {r * scalar, g * scalar, b * scalar};
}

Color Color::operator/(const GLfloat &scalar) {
    return {r / scalar, g / scalar, b / scalar};
}

Color &Color::operator+=(const Color &other) {
    this->r += other.r;
    this->g += other.g;
    this->b += other.b;
    return *this;
}

Color &Color::operator-=(const Color &other) {
    this->r -= other.r;
    this->g -= other.g;
    this->b -= other.b;
    return *this;
}

Color &Color::operator*=(const GLfloat &scalar) {
    this->r *= scalar;
    this->g *= scalar;
    this->b *= scalar;
    return *this;
}

Color &Color::operator/=(const GLfloat &scalar) {
    this->r /= scalar;
    this->g /= scalar;
    this->b /= scalar;
    return *this;
}

bool Color::operator==(const Color &other) {
    return this->r == other.r && this->g == other.g && this->b == other.b;
}

bool Color::operator!=(const Color &other) {
    return this->r != other.r || this->g != other.g || this->b != other.b;
}

Color Color::random() {
    return {utils::random(), utils::random(), utils::random()};
}


Color Color::random(GLfloat min, GLfloat max) {
    return {utils::random(min, max), utils::random(min, max), utils::random(min, max)};
}

Color Color::random(Color min, Color max) {
    return {utils::random(min.r, max.r), utils::random(min.g, max.g), utils::random(min.b, max.b)};
}
