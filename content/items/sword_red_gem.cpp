#include "sword_red_gem.h"

#include "engine.h"
#include "hit.h"
#include "swing.h"

Sword_Red_Gem::Sword_Red_Gem(int damage)
    :Item("sword_red_gem"), damage{damage}{}

void Sword_Red_Gem::use(Engine& engine , Entity& attacker, Entity& defender) {
    engine.events.create_event<Swing>(sprite, attacker.get_direction());
    engine.events.create_event<Hit>(defender, damage);
}
