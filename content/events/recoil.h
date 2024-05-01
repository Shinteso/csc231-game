#pragma once

#include "sprite.h"
#include "event.h"

class Recoil : public Event {
public:
    Recoil(Sprite& sprite, Vec direction);

    // execute : sprite.shift += (dx, dy)
    void execute(Engine& engine) override;

    //reset original spirte
   void when_done(Engine& engine) override;

private:
    Sprite& sprite; // original weapon sprite
    Sprite copy; // copy so that we can reset it after animation
    Vec direction; // which direction to shift
};