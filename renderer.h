//
// Created by imloul on 8/24/2023.
//

#ifndef SOLAR_SYSTEM_RENDERER_H
#define SOLAR_SYSTEM_RENDERER_H

#include <vector>
#include "drawable.h"


// this class will be responsible for rendering the solar system
// it will render drawable objects
class renderer {
public:
    renderer();

    ~renderer();

    void render();

    void add(Drawable* drawable);

    void remove(Drawable* drawable);

    void clear();

private:
    std::vector<Drawable*> drawables;
};


#endif //SOLAR_SYSTEM_RENDERER_H
