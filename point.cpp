//
// Created by imloul on 8/23/2023.
//

#include "point.h"
#include <cmath>
#include "utils.h"


Point::Point(GLfloat x, GLfloat y) {
    this->x = x;
    this->y = y;
}

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point Point::operator+(const Point &other) const {
    return {x + other.x, y + other.y};
}

Point Point::operator-(const Point &other) const {
    return {x - other.x, y - other.y};
}

Point Point::operator*(const GLfloat &scalar) const {
    return {x * scalar, y * scalar};
}

Point Point::operator/(const GLfloat &scalar) const {
    return {x / scalar, y / scalar};
}

Point &Point::operator+=(const Point &other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Point &Point::operator-=(const Point &other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Point &Point::operator*=(const GLfloat &scalar) {
    this->x *= scalar;
    this->y *= scalar;
    return *this;
}

Point &Point::operator/=(const GLfloat &scalar) {
    this->x /= scalar;
    this->y /= scalar;
    return *this;
}

bool Point::operator==(const Point &other) const {
    return this->x == other.x && this->y == other.y;
}

bool Point::operator!=(const Point &other) const {
    return this->x != other.x || this->y != other.y;
}

GLfloat Point::magnitude() const {
    return sqrt(x * x + y * y);
}

Point Point::normalize() const {
    return {x / magnitude(), y / magnitude()};
}

Point &Point::normalizeSelf() {
    GLfloat magnitude = this->magnitude();
    this->x /= magnitude;
    this->y /= magnitude;
    return *this;
}

GLfloat Point::dot(const Point &other) const {
    return x * other.x + y * other.y;
}

GLfloat Point::cross(const Point &other) const {
    return x * other.y - y * other.x;
}

Point Point::project(const Point &other) const {
    return other * (this->dot(other) / other.dot(other));
}

Point Point::reflect(const Point &normal) const {
    return *this - normal * 2 * this->dot(normal);
}

Point Point::rotate(GLfloat angle) const {
    GLfloat cosAngle = cos(angle);
    GLfloat sinAngle = sin(angle);
    return {x * cosAngle - y * sinAngle, x * sinAngle + y * cosAngle};
}

Point Point::random() {
    return {utils::random(), utils::random()};
}