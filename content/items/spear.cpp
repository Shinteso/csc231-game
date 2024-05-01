#include "spear.h"

#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "animation.h"

Spear::Spear(int damage)
    :Item("shotgun"), damage{damage}{}

void Spear::use(Engine& engine , Entity& attacker , Entity& defender) {
   Vec direction = defender.get_position() - attacker.get_position();

   auto thrust = engine.events.create_event<Thrust>(sprite, direction);
    std::shared_ptr<Event> explosion = std::make_shared<Animation>("explosion", defender.get_position());
    explosion->add_next(Hit{defender, damage});
    thrust->add_next(explosion);

}
