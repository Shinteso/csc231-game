#pragma once

#include "item.h"
#include "entity.h"

class NextFloor : public Item {
public:
    explicit NextFloor(int level);
    void interact(Engine& engine, Entity& entity) override;

private:
    int level;
};