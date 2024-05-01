#include "recoil.h"

constexpr int duration = 3; //number of frames
constexpr int delta = 3;
Recoil::Recoil(Sprite& sprite , Vec direction)
    : Event{duration}, sprite{sprite}, copy{sprite},  direction{direction}{
    // orient the weapon towards direction
    sprite.center = sprite.size / 2;
    sprite.shift.y -= sprite.size.x / 4;

    if (direction == Vec{1, 0}) { // right
        sprite.shift.y += sprite.size.y/2;

    }
    else if (direction == Vec{-1, 0}) { // left
        sprite.shift.y += sprite.size.y/2;

    }
    else if (direction == Vec{0, 1}) { // up

        this->direction = -1 * direction;
    }
    else { // down

        sprite.shift.y += sprite.size.y;
        this->direction = -1 * direction;
    }
}

void Recoil::execute(Engine& ) {
    //shift in pixels (16 per tile)
    sprite.shift += direction* -1 * delta;
}

void Recoil::when_done(Engine&) {
    sprite = copy;
}


