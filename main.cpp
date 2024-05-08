#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>
#include "next_floor.h"

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_dragon(hero);

        for (int i = 0; i < 2; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_orc_masked(monster);
        }
        for (int i = 0; i < 2; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_necromancer(monster);
        }
        for (int i = 0; i < 2; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_zombie(monster);
        }

            auto staircase = std::make_shared<NextFloor>(1);
            staircase->sprite = engine.graphics.get_sprite(staircase->name);
            Vec position = engine.dungeon.random_open_room_tile();
            Tile& tile = engine.dungeon.get_tile(position);
            tile.item = staircase;

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
