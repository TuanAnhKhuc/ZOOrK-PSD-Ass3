//
// Created by Richard Skarbez on 5/7/23.
//

#ifndef ZOORK_PLAYER_H
#define ZOORK_PLAYER_H

#include "Character.h"
#include "Location.h"
#include "NullRoom.h"
#include <vector>
#include "Item.h"

class Player : public Character {
public:
    static Player *instance() {
        // Note: lazy instantiation of the singleton Player object
        if (!playerInstance) {
            playerInstance = new Player();
        }
        return Player::playerInstance;
    }

    void setCurrentRoom(Room*);

    Room* getCurrentRoom() const;

    Player(const Player &) = delete;

    Player &operator=(const Player &) = delete;

    void addItem(Item* item);
    bool removeItem(const std::string& name);
    bool hasItem(const std::string& name) const;  // ✅ Add this

    Item* getItem(const std::string& name);
    const std::vector<Item*>& getInventory() const;

private:
    static Player *playerInstance;
    Room* currentRoom;
    std::vector<Item*> inventory;

    Player() : Character("You", "You are a person, alike in dignity to any other, but uniquely you."),
               currentRoom(new NullRoom()) {}
};

#endif //ZOORK_PLAYER_H
