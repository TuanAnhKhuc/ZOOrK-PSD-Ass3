#include "Door.h"
#include <iostream>

// Constructor for Door
// Inherits from Passage, but includes a required item to unlock
Door::Door(Room* from, Room* to, const std::string& direction, const std::string& requiredItemName)
    : Passage(from->getName() + "_to_" + to->getName(),  // Name of the door
              "A locked door that requires a " + requiredItemName + " to pass.", // Description
              from, to),  // Connected rooms
      requiredItem(requiredItemName) {} // Store the item needed

// Override canTraverse to check if player has the required item
bool Door::canTraverse(Player* player) const {
    return player && player->hasItem(requiredItem); // Only true if player has the key/item
}

// Override traverse to include unlock message and allow/deny access
void Door::traverse(Player* player) const {
    if (canTraverse(player)) {
        std::cout << "You unlock the door using the " << requiredItem << " and pass through.\n";
        player->setCurrentRoom(getTo()); // Move player to the target room
    } else {
        std::cout << "The door is locked. You need a " << requiredItem << " to pass.\n";
        // Player is not moved if they lack the item
    }
}
