#pragma once
#include "entity.h"
namespace Monsters {
    void make_orc_masked(const std::shared_ptr<Entity>& monster);
    void make_necromancer(const std::shared_ptr<Entity>& monster);
    void make_zombie(const std::shared_ptr<Entity>& monster);
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity);
}
