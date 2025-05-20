//
// Created by Richard Skarbez on 5/7/23.
//

#include "Passage.h"
#include "Player.h"
#include <utility>
#include "PassageDefaultEnterCommand.h"

std::string Passage::oppositeDirection(const std::string &s) {
    if (s == "north") return "south";
    else if (s == "south") return "north";
    else if (s == "east") return "west";
    else if (s == "west") return "east";
    else if (s == "up") return "down";
    else if (s == "down") return "up";
    else if (s == "in") return "out";
    else if (s == "out") return "in";
    else return "unknown_direction";
}

// Static method to create a basic passage and optionally a return path
void Passage::createBasicPassage(Room* from, Room* to,
                                 const std::string &direction, bool bidirectional = true) {
    // Name the passage (e.g., "RoomA_to_RoomB")
    std::string passageName = from->getName() + "_to_" + to->getName();
    auto temp1 = std::make_shared<Passage>(passageName, "A totally normal passageway.", from, to);
    from->addPassage(direction, temp1);
    // If bidirectional, create reverse path as well
    if (bidirectional) {
        std::string passageName2 = to->getName() + "_to_" + from->getName();
        auto temp2 = std::make_shared<Passage>(passageName, "A totally normal passageway.", to, from);
        to->addPassage(oppositeDirection(direction), temp2);
    }
}

// Constructor: basic passage with default enter command
Passage::Passage(const std::string &n, const std::string &d, Room* from, Room* to)
        : Location(n, d), fromRoom(from), toRoom(to) {
    setEnterCommand(std::make_shared<PassageDefaultEnterCommand>(this));
}

// Constructor: allows for custom enter command
Passage::Passage(const std::string &n, const std::string &d, std::shared_ptr<Command> c, Room* from,
                 Room* to)
        : Location(n, d, std::move(c)), fromRoom(from), toRoom(to) {}

// Setter for the source room
void Passage::setFrom(Room* r) {
    fromRoom = r;
}

// Getter for the source room
Room* Passage::getFrom() const {
    return fromRoom;
}

// Setter for the destination room
void Passage::setTo(Room* r) {
    toRoom = r;
}

// Getter for the destination room
Room* Passage::getTo() const {
    return toRoom;
}

// Determines if the player is allowed to use this passage
// Always returns true in basic Passage, but can be overridden (e.g., in Door)
bool Passage::canTraverse(Player* player) const {
    return true;
}

// Moves the player to the target room if allowed
void Passage::traverse(Player* player) const {
    if (player) {
        player->setCurrentRoom(toRoom);
    }
}