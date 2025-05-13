//
// Created by Richard Skarbez on 5/7/23.
//

#include "NullPassage.h"

NullPassage::NullPassage(Room* from) : Passage("null", "Time is a flat circle.", from, from) {}

// Override enter() to provide clear feedback to the player
void NullPassage::enter() {
    std::cout << "You can't go that way.\n";
}