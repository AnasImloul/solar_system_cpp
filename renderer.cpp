//
// Created by imloul on 8/24/2023.
//

#include "renderer.h"

renderer::renderer() = default;

renderer::~renderer() = default;

void renderer::render() {
    for (auto& drawable : drawables) {
        drawable->draw();
    }
}

void renderer::add(Drawable* drawable) {
    drawables.push_back(drawable);
}

void renderer::remove(Drawable* drawable) {
    for (auto it = drawables.begin(); it != drawables.end(); ++it) {
        if (*it == drawable) {
            drawables.erase(it);
            break;
        }
    }
}

void renderer::clear() {
    drawables.clear();
}

