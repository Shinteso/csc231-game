#pragma once
#include "item.h"

class Sword_Red_Gem : public Item {
public:
    explicit Sword_Red_Gem(int damage);
    void use(Engine& engine, Entity& attack, Entity& defender) override;

private:
    int damage;
};