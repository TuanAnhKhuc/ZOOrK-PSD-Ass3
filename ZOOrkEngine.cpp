//
// Created by Richard Skarbez on 5/7/23.
//

#include "ZOOrkEngine.h"

#include <utility>

ZOOrkEngine::ZOOrkEngine(std::shared_ptr<Room> start) {
    player = Player::instance();
    player->setCurrentRoom(start.get());
    player->getCurrentRoom()->enter();
}

void ZOOrkEngine::run() {
    while (!gameOver) {
        std::cout << "> ";

        std::string input;
        std::getline(std::cin, input);

        std::vector<std::string> words = tokenizeString(input);
        std::string command = words[0];
        std::vector<std::string> arguments(words.begin() + 1, words.end());
    if (command == "go") {
        handleGoCommand(arguments);
    } else if ((command == "look") || (command == "inspect")) {
        handleLookCommand(arguments);
    } else if ((command == "take") || (command == "get")) {
        handleTakeCommand(arguments);
    } else if (command == "drop") {
        handleDropCommand(arguments);
    } else if (command == "inventory") { // 👈 Add this
        handleInventoryCommand();
    } else if (command == "quit") {
        handleQuitCommand(arguments);
    }  
    }
}

void ZOOrkEngine::handleGoCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Go where?\n";
        return;
    }

    std::string direction;
    if (arguments[0] == "n" || arguments[0] == "north") direction = "north";
    else if (arguments[0] == "s" || arguments[0] == "south") direction = "south";
    else if (arguments[0] == "e" || arguments[0] == "east") direction = "east";
    else if (arguments[0] == "w" || arguments[0] == "west") direction = "west";
    else if (arguments[0] == "u" || arguments[0] == "up") direction = "up";
    else if (arguments[0] == "d" || arguments[0] == "down") direction = "down";
    else direction = arguments[0];

    Room* currentRoom = player->getCurrentRoom();
    auto passage = currentRoom->getPassage(direction);

    // ✅ Prevent switching rooms if this is a NullPassage
    if (dynamic_cast<NullPassage*>(passage.get()) != nullptr) {
        passage->enter();  // just say "you can't go that way"
        return;
    }

    player->setCurrentRoom(passage->getTo());
    passage->enter();
}

void ZOOrkEngine::handleLookCommand(std::vector<std::string> arguments) {
    Room* currentRoom = player->getCurrentRoom();

    if (arguments.empty()) {
        // No target: describe the current room
        std::cout << currentRoom->getDescription() << "\n";
    } else {
        std::string targetName = arguments[0];
        GameObject* target = currentRoom->getObject(targetName);

        if (target != nullptr) {
            std::cout << target->getDescription() << "\n";
        } else {
            std::cout << "You don't see any \"" << targetName << "\" here.\n";
        }
    }
}

void ZOOrkEngine::handleTakeCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Take what?\n";
        return;
    }

    std::string itemName = arguments[0];
    Room* currentRoom = player->getCurrentRoom();
    Item* item = currentRoom->getItem(itemName);

    if (item != nullptr) {
        player->addItem(item);
        currentRoom->removeItem(itemName);
        std::cout << "You take the " << itemName << ".\n";
    } else {
        std::cout << "There is no \"" << itemName << "\" here.\n";
    }
}


void ZOOrkEngine::handleDropCommand(std::vector<std::string> arguments) {
    if (arguments.empty()) {
        std::cout << "Drop what?\n";
        return;
    }

    std::string itemName = arguments[0];
    Item* item = player->getItem(itemName);

    if (item != nullptr) {
        Room* currentRoom = player->getCurrentRoom();
        player->removeItem(itemName);
        currentRoom->addItem(item);
        std::cout << "You drop the " << itemName << ".\n";
    } else {
        std::cout << "You don't have a \"" << itemName << "\".\n";
    }
}


void ZOOrkEngine::handleQuitCommand(std::vector<std::string> arguments) {
    std::string input;
    std::cout << "Are you sure you want to QUIT?\n> ";
    std::cin >> input;
    std::string quitStr = makeLowercase(input);

    if (quitStr == "y" || quitStr == "yes") {
        gameOver = true;
    }
}

void ZOOrkEngine::handleInventoryCommand() {
    std::cout << "You are carrying:\n";

    bool empty = true;
    for (const auto& item : player->getInventory()) {
        std::cout << "- " << item->getName() << ": " << item->getDescription() << "\n";
        empty = false;
    }

    if (empty) {
        std::cout << "Nothing.\n";
    }
}

const std::vector<Item*>& Player::getInventory() const {
    return inventory;
}


std::vector<std::string> ZOOrkEngine::tokenizeString(const std::string &input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, ' ')) {
        tokens.push_back(makeLowercase(token));
    }

    return tokens;
}

std::string ZOOrkEngine::makeLowercase(std::string input) {
    std::string output = std::move(input);
    std::transform(output.begin(), output.end(), output.begin(), ::tolower);

    return output;
}
