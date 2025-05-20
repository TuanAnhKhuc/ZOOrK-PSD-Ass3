//
// Created by Richard Skarbez on 5/7/23.
//

#include "NullPassage.h"
#include "Room.h"

#include <utility>


Room::Room(const std::string &n, const std::string &d) : Location(n, d) {
    // Each room uses RoomDefaultEnterCommand for default behavior when entering
    enterCommand = std::make_shared<RoomDefaultEnterCommand>(this);
}

Room::Room(const std::string &n, const std::string &d, std::shared_ptr<Command> c) : Location(n, d, std::move(c)) {}

// Adds a Passage (connection to another room) in a specific direction
void Room::addPassage(const std::string &direction, std::shared_ptr<Passage> p) {
    passageMap[direction] = std::move(p);
}

// Removes a passage from the room in a given direction
void Room::removePassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        passageMap.erase(direction);
    }
}

// Gets a passage in a specific direction
// If no passage exists, returns a NullPassage (invalid path handler)
std::shared_ptr<Passage> Room::getPassage(const std::string &direction) {
    if (passageMap.contains(direction)) {
        return passageMap[direction];
    } else {
        std::cout << "It is impossible to go " << direction << "!\n";
        return std::make_shared<NullPassage>(this);
    }
}

// Adds an Item to the Room's inventory
void Room::addItem(Item* item) {
    items.push_back(item);
}

// Removes an Item from the Room by name
// Returns true if found and removed
bool Room::removeItem(const std::string& name) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getName() == name) {
            items.erase(it);
            return true;
        }
    }
    return false;
}

// Gets an Item pointer by name (does not remove it)
Item* Room::getItem(const std::string& name) {
    for (Item* item : items) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}

// Looks for any object (currently only Items) in the Room by name
// This is used for "look" or "inspect" commands
GameObject* Room::getObject(const std::string& name) {
    for (Item* item : items) {
        if (item->getName() == name) {
            return item;
        }
    }
    return nullptr;
}
