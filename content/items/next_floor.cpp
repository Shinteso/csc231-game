#include "next_floor.h"
#include "engine.h"
#include "builder.h"
#include "settings.h"
#include "../entities/monsters.h"
#include "decorator.h"



NextFloor::NextFloor(int level)
    :Item{"staircase"}, level{level}{}

void NextFloor::interact(Engine& engine , Entity& entity) {
    if(&entity == engine.hero.get()) {
        Builder builder {engine.settings.room_placement_attempts};
        auto [layout, rooms] = builder.generate(engine.settings.map_width, engine.settings.map_height);
        Decorator decorator {engine.graphics, layout, rooms};
        engine.dungeon = decorator.create_dungeon();
        entity.move_to(engine.dungeon.random_open_room_tile());
        Vec pos = entity.get_position();
        Tile& t = engine.dungeon.get_tile(pos);
        t.entity = &entity;
        for (int i = 0; i < level+1; ++i) {
            for (i = 0; i < 2; ++i) {
                std::shared_ptr<Entity> monster0 = engine.create_monster();
                Monsters::make_necromancer(monster0);
                std::shared_ptr<Entity> monster1 = engine.create_monster();
                Monsters::make_orc_masked(monster1);
                std::shared_ptr<Entity> monster2 = engine.create_monster();
                Monsters::make_zombie(monster2);
            }
        }
    }
}