#pragma once

#include "item.h"
#include "entity.h"
class Knife : public Item {
public:
    explicit Knife(int damage);
    void use (Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};
