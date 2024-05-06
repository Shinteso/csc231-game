#include "monsters.h"
#include "action.h"
#include"rest.h"
#include "move.h"
#include "engine.h"
#include "randomness.h"
#include "wander.h"
#include "bite.h"
#include "sword_red_gem.h"
#include "knife.h"

namespace Monsters{
    void make_orc_masked(const std::shared_ptr<Entity>& monster){
        monster->set_sprite("orc_masked");
        monster->set_max_health(45);
        monster->behavior = behavior;
        monster->add_to_inventory(std::make_shared<Sword_Red_Gem>(15));

    }
    void make_necromancer(const std::shared_ptr<Entity>& monster) {
        monster->set_sprite("necromancer");
        monster->set_max_health(30);
        monster->behavior = behavior;
        monster->add_to_inventory(std::make_shared<Knife>(12));
    }
    void make_zombie(const std::shared_ptr<Entity>& monster) {
        monster->set_sprite("zombie");
        monster->set_max_health(40);
        monster->behavior = behavior;
        monster->add_to_inventory(std::make_shared<Bite>(10));
    }
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
      if(entity.is_visible() && engine.hero) {
          auto path = engine.dungeon.calculate_path(entity.get_position() , engine.hero->get_position());

          if (path.size() > 1) {
              auto direction = path.at(1) - path.at(0);
              return std::make_unique<Move>(direction);
          }

      }
      // If monster does not see Hero
        if (probability(66)) {
            return std::make_unique<Wander>();
        }
        else {
            return std::make_unique<Rest>();
        }
    }
}
