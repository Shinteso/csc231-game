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
        engine.entities.add(engine.hero);
        Builder builder {engine.settings.room_placement_attempts};
        auto [layout, rooms] = builder.generate(engine.settings.map_width, engine.settings.map_height);
        Decorator decorator {engine.graphics, layout, rooms};
        engine.dungeon = decorator.create_dungeon();
        for (auto& e : engine.entities) {
            if (e != engine.hero) {
                engine.remove_entity(*e);
            }
        }
        Vec new_position = engine.dungeon.random_open_room_tile();
        entity.move_to(new_position);
        Tile& tile = engine.dungeon.get_tile(new_position);
        tile.entity = engine.hero.get();


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