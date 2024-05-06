#include "heroes.h"

#include "action.h"

#include "engine.h"

#include "rest.h"
#include "move.h"
#include "closedoor.h"
#include "sword_red_gem.h"
#include "launcher.h"
#include "knife.h"

namespace Heroes {
    void make_dragon(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("dragon");
        hero->set_max_health(1000);
        hero->add_to_inventory(std::make_shared<Sword_Red_Gem>(18));
        hero->add_to_inventory(std::make_shared<Launcher>(12));
        hero->add_to_inventory(std::make_shared<Knife>(5));
        hero->behavior = behavior;
    }
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
        std::string key = engine.input.get_last_keypress();
        if (key == "W") {
            return std::make_unique<Move>(Vec{0, 1});
        }
        else if (key == "D") {
            return std::make_unique<Move>(Vec{1, 0});
        }
        else if (key == "S") {
            return std::make_unique<Move>(Vec{0, -1});
        }
        else if (key == "A") {
            return std::make_unique<Move>(Vec{-1 , 0});
        }
        else if (key == "R") {
            return std::make_unique<Rest>();
        }
        else if(key == "C"){
            return std::make_unique<CloseDoor>();
        }
        else if (!key.empty() && std::isdigit(key.at(0))) {
            int item_num = std::stoi(key) - 1; // "1"  ,-> index 0
            entity.select_item(item_num);
        }
        return nullptr;
    }
}