#include "move.h"

#include "tile.h"

#include "entity.h"

#include "engine.h"

#include "opendoor.h"

#include "rest.h"

#include "attack.h"

Move::Move(Vec direction)
: direction({direction}){}

Result Move::perform(Engine& engine , std::shared_ptr<Entity> entity) {

    entity->change_direction(direction);
    Vec position = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(position);
    //check if wall
    if (tile.is_wall()) {
        return failure();
    }
    else if (tile.has_door() && !tile.door->is_open()){
        return alternative(OpenDoor(*tile.door));
    }
    else if (tile.has_entity()) {
        if (entity->get_team() != tile.entity->get_team()){
            return alternative(Attack(*tile.entity));
        }
    }
        //must be an empty tile or not a wall
        entity->move_to(position);
        return success();
}