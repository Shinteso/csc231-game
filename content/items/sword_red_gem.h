#pragma once
#include "item.h"
#include "entity.h"

class Sword_Red_Gem : public Item {
public:
    explicit Sword_Red_Gem(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};