//
// Created by imloul on 8/23/2023.
//

#include "color.h"
#include "utils.h"


Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

Color::Color(GLfloat r, GLfloat g, GLfloat b): r(r), g(g), b(b), a(1) {}

Color::Color(): r(0), g(0), b(0), a(1) {}

Color Color::operator+(const Color &other) const {
    return {r + other.r, g + other.g, b + other.b, a + other.a};
}

Color Color::operator-(const Color &other) const {
    return {r - other.r, g - other.g, b - other.b, a - other.a};
}

Color Color::operator*(const GLfloat &scalar) {
    return {r * scalar, g * scalar, b * scalar, a * scalar};
}

Color Color::operator/(const GLfloat &scalar) {
    return {r / scalar, g / scalar, b / scalar, a / scalar};
}

Color &Color::operator+=(const Color &other) {
    this->r += other.r;
    this->g += other.g;
    this->b += other.b;
    this->a += other.a;
    return *this;
}

Color &Color::operator-=(const Color &other) {
    this->r -= other.r;
    this->g -= other.g;
    this->b -= other.b;
    this->a -= other.a;
    return *this;
}

Color &Color::operator*=(const GLfloat &scalar) {
    this->r *= scalar;
    this->g *= scalar;
    this->b *= scalar;
    this->a *= scalar;
    return *this;
}

Color &Color::operator/=(const GLfloat &scalar) {
    this->r /= scalar;
    this->g /= scalar;
    this->b /= scalar;
    this->a /= scalar;
    return *this;
}

bool Color::operator==(const Color &other) {
    return this->r == other.r && this->g == other.g && this->b == other.b && this->a == other.a;
}

bool Color::operator!=(const Color &other) {
    return this->r != other.r || this->g != other.g || this->b != other.b || this->a != other.a;
}

Color Color::random() {
    return {utils::random(), utils::random(), utils::random(), 1};
}

Color Color::random(GLfloat alpha) {
    return {utils::random(), utils::random(), utils::random(), alpha};
}

Color Color::random(GLfloat min, GLfloat max) {
    return {utils::random(min, max), utils::random(min, max), utils::random(min, max), 1};
}

Color Color::random(GLfloat min, GLfloat max, GLfloat alpha) {
    return {utils::random(min, max), utils::random(min, max), utils::random(min, max), alpha};
}

Color Color::random(Color min, Color max) {
    return {utils::random(min.r, max.r), utils::random(min.g, max.g), utils::random(min.b, max.b), 1};
}
