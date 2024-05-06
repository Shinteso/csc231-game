#include "launcher.h"

#include "engine.h"
#include "hit.h"
#include "recoil.h"
#include "animation.h"


Launcher::Launcher(int damage)
        :Item("launcher"), damage{damage}{}

void Launcher::use(Engine& engine , Entity& attacker , Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();

    auto recoil = engine.events.create_event<Recoil>(sprite, direction);
    std::shared_ptr<Event> explosion = std::make_shared<Animation>("explosion", defender.get_position());
    explosion->add_next(Hit{defender, damage});
    recoil->add_next(explosion);


}
