#include "animation.h"


Animation::Animation(std::string name, Vec position)
:name{name}, position{position} {}

void Animation::execute(Engine& engine) {
    if (frame_count == 0) { // Event::frame_count
        sprite = engine.graphics.get_animated_sprite("explosion", 1);
        //Event::number_of_frames matches the animation number of frames
        number_of_frames = sprite.number_of_frames();
    }

    engine.camera.add_overlay(position, sprite.get_sprite());
    sprite.update(); // Moves to next frame
}
