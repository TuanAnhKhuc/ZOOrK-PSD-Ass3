//
// Created by Richard Skarbez on 5/7/23.
//

#include "Player.h"

Player *Player::playerInstance = nullptr;

// Sets the room the player is currently in
void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

// Returns the room the player is currently in
Room* Player::getCurrentRoom() const {
    return currentRoom;
}

// Adds an item to the player's inventory
void Player::addItem(Item* item) {
    inventory.push_back(item);
}

// Removes an item from the player's inventory by name
// Returns true if the item was found and removed
bool Player::removeItem(const std::string& name) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getName() == name) {
            inventory.erase(it); // Remove from inventory
            return true;
        }
    }
    return false;  // Item not found
}

// Returns a pointer to an item in inventory by name (without removing it)
Item* Player::getItem(const std::string& name) {
    for (Item* item : inventory) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

// Checks if player has an item by name
bool Player::hasItem(const std::string& name) const {
    for (Item* item : inventory) {
        // Extra null check for safety
        if (item && item->getName() == name) {
            return true;
        }
    }
    return false;
}
