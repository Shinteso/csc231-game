#include "animation.h"

#include <utility>


Animation::Animation(std::string name, Vec position)
:name{std::move(name)}, position{position} {}

void Animation::execute(Engine& engine) {
    if (frame_count == 0) { // Event::frame_count
        sprite = engine.graphics.get_animated_sprite(name , 1);
        //Event::number_of_frames matches the animation number of frames
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(position, sprite.get_sprite());
    sprite.update(); // Moves to next frame
}
