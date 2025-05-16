#include "Door.h"
#include <iostream>

Door::Door(Room* from, Room* to, const std::string& direction, const std::string& requiredItemName)
    : Passage(from->getName() + "_to_" + to->getName(),
              "A locked door that requires a " + requiredItemName + " to pass.",
              from, to),
      requiredItem(requiredItemName) {}

bool Door::canTraverse(Player* player) const {
    return player && player->hasItem(requiredItem);
}

void Door::traverse(Player* player) const {
    if (canTraverse(player)) {
        std::cout << "You unlock the door using the " << requiredItem << " and pass through.\n";
        player->setCurrentRoom(getTo());
    } else {
        std::cout << "The door is locked. You need a " << requiredItem << " to pass.\n";
    }
}
