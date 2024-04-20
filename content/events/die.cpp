#include "die.h"

#include "engine.h"
#include "entity.h"
Die::Die(Entity& entity)
:entity{entity} {}

void Die::execute(Engine& engine) {
    engine.remove_entity(entity);
}
