#include "move.h"

#include "tile.h"

#include "entity.h"

#include "engine.h"

#include "opendoor.h"




Move::Move(Vec direction)
: direction({direction}){}



Result Move::perform(Engine& engine , std::shared_ptr<Entity> entity) {

    entity->change_direction(direction);
    Vec position = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(position);
   //chcel
    if (tile.is_wall() || tile.has_entity()) {
        return failure();
   }
    if (tile.has_door() && !tile.door->is_open()){
        return alternative(OpenDoor(*tile.door));
    }
    //must be an empty tile or not a wall
    entity->move_to(position);
    return success();
}
