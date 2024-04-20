#include "hit.h"

#include "die.h"
#include "entity.h"

Hit::Hit(Entity& entity , int damage)
:entity{entity}, damage{damage}{}

void Hit::execute(Engine&) {
    entity.take_damage(damage);// reduce health
}

void Hit::when_done(Engine&) {
    if (!entity.is_alive()) {
        add_next(Die{entity}); //remove from the game
    }
}
