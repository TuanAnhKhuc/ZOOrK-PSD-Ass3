#pragma once

#include "Passage.h"
#include "Player.h"
#include <string>

class Door : public Passage {
public:
    Door(Room* from, Room* to, const std::string& direction, const std::string& requiredItemName);

    bool canTraverse(Player* player) const override;
    void traverse(Player* player) const override;

private:
    std::string requiredItem;
};
