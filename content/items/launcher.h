#pragma once

#include "item.h"
#include "entity.h"

class Launcher : public Item {
public:
    explicit Launcher(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};
