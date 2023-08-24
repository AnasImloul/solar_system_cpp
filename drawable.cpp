//
// Created by imloul on 8/23/2023.
//

#include "drawable.h"


Drawable::Drawable(Point& pos, GLfloat size, Color color) {
    this->pos = pos;
    this->size = size;
    this->color = std::move(color);
}

GLfloat Drawable::getX() const {
    return pos.x;
}

GLfloat Drawable::getY() const {
    return pos.y;
}

GLint Drawable::getSize() const {
    return size;
}

Color Drawable::getColor() const {
    return color;
}

void Drawable::setX(GLfloat x) {
    pos.x = x;
}

void Drawable::setY(GLfloat y) {
    pos.y = y;
}

void Drawable::setSize(GLint size) {
    this->size = size;
}

void Drawable::setColor(Color color) {
    this->color = std::move(color);
}

void Drawable::update(const Point& pos) {
    this->pos = pos;
}
