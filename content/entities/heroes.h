#pragma once
#include <memory>
#include "entity.h"

namespace Heroes {
    void make_dragon(std::shared_ptr<Entity>& hero);
    std::unique_ptr<Action> behavior(Engine& engine, Entity&);
}