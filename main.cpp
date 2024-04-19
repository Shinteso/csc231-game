#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_dragon(hero);

        for (int i = 0; i < 5; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_orc_masked(monster);
        }
        for (int i = 0; i < 5; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_necromancer(monster);
        }
        for (int i = 0; i < 5; ++i) {
            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_zombie(monster);
        }
        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
