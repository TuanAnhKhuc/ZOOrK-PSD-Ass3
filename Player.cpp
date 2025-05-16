//
// Created by Richard Skarbez on 5/7/23.
//

#include "Player.h"

Player *Player::playerInstance = nullptr;

void Player::setCurrentRoom(Room* room) {
    currentRoom = room;
}

Room* Player::getCurrentRoom() const {
    return currentRoom;
}

void Player::addItem(Item* item) {
    inventory.push_back(item);
}

bool Player::removeItem(const std::string& name) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if ((*it)->getName() == name) {
            inventory.erase(it);
            return true;
        }
    }
    return false;
}

Item* Player::getItem(const std::string& name) {
    for (Item* item : inventory) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

bool Player::hasItem(const std::string& name) const {
    for (Item* item : inventory) {
        if (item && item->getName() == name) {
            return true;
        }
    }
    return false;
}
