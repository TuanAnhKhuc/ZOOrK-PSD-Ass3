#include "RoomDefaultEnterCommand.h"
#include "Passage.h"
#include "Player.h"
#include "Room.h"
#include "ZOOrkEngine.h"
#include "Door.h"


int main() {
 // --- Room Creation Section ---

    // Create each room with a name and description.
    // These descriptions give hints and directions to the player.
    auto start = std::make_shared<Room>(
        "Start",
        "You are standing in an open field west of a white house, with a boarded front door.\n "
        "You see a torch lying in the grass. You can go south to face the house."
    );

    auto south_of_house = std::make_shared<Room>(
        "South of House",
        "You are facing the south side of a white house. There is no door here, and all the windows are barred.\n "
        "You can go east to move behind the house or north to return to the field."
    );

    auto behind_house = std::make_shared<Room>(
        "Behind House",
        "You are behind the white house. A path leads into the forest to the east.\n "
        "In one corner of the house there is a small window which is slightly ajar.\n "
        "You can go east to the forest path, west to the south side, or north to climb the hill."
    );

    auto forest_path = std::make_shared<Room>(
        "Forest Path",
        "You are on a path in a dark forest. The trees are thick and block out most of the light.\n "
        "A rope lies tangled in the underbrush. You can go west to return behind the house or south toward a cave entrance."
    );

    auto cave_entrance = std::make_shared<Room>(
        "Cave Entrance",
        "You stand at the entrance to a dark cave. A cold breeze emerges from within.\n "
        "A shovel is half-buried in the dirt nearby. You can go north to the forest or in to enter the cave."
    );

    auto dark_cave = std::make_shared<Room>(
        "Dark Cave",
        "You are in a pitch-black cave. The walls are damp and echo your every step.\n "
        "You notice something metallic on the ground — it looks like a key.\n "
        "You can go up to leave the cave or down to explore further."
    );

    auto underground_lake = std::make_shared<Room>(
        "Underground Lake",
        "You are by the edge of an underground lake. The water is still and eerily clear.\n "
        "A glowing vial floats gently near the shore. You can go up to return to the cave."
    );

    auto hilltop = std::make_shared<Room>(
    "Hilltop",
    "You stand on a hilltop with a view of the entire forest and house.\n"
    "A telescope sits mounted here, aimed at the stars.\n"
    "**A locked door leads up into the observatory.**\n"
    "You can go south to return behind the house or up into the observatory."
    );  

    auto observatory = std::make_shared<Room>(
        "Observatory",
        "You are in an old observatory. Dusty telescopes point at the sky.\n "
        "A map is spread out on a table, detailing parts of the house and forest.\n "
        "You can go down to the hilltop or enter a hidden trapdoor above stairs to find a treasure."
    );

    auto secret_room = std::make_shared<Room>(
        "Secret Room",
        "You have discovered a secret room hidden above in the observatory.\n "
        "A glowing orb pulses softly on a pedestal. You can go down to return to the observatory."
    );
// --- Passage Creation Section ---

// Connect rooms together using passages (some directional, some locked)
// BasicPassages are two-way unless otherwise stated
    Passage::createBasicPassage(start.get(), south_of_house.get(), "south", true);
    Passage::createBasicPassage(south_of_house.get(), start.get(), "north", true);

    Passage::createBasicPassage(south_of_house.get(), behind_house.get(), "east", true);
    Passage::createBasicPassage(behind_house.get(), south_of_house.get(), "west", true);

    Passage::createBasicPassage(behind_house.get(), forest_path.get(), "east", true);
    Passage::createBasicPassage(forest_path.get(), behind_house.get(), "west", true);

    Passage::createBasicPassage(forest_path.get(), cave_entrance.get(), "south", true);
    Passage::createBasicPassage(cave_entrance.get(), forest_path.get(), "north", true);

    Passage::createBasicPassage(cave_entrance.get(), dark_cave.get(), "in", true);
    Passage::createBasicPassage(dark_cave.get(), cave_entrance.get(), "up", true);

    Passage::createBasicPassage(dark_cave.get(), underground_lake.get(), "down", true);
    Passage::createBasicPassage(underground_lake.get(), dark_cave.get(), "up", true);

    Passage::createBasicPassage(behind_house.get(), hilltop.get(), "north", true);
    Passage::createBasicPassage(hilltop.get(), behind_house.get(), "south", true);

// Create a DOOR from hilltop to observatory (requires "key")
    auto doorToObservatory = std::make_shared<Door>(hilltop.get(), observatory.get(), "up", "key");
    hilltop->addPassage("up", doorToObservatory); // Player needs key to use this

// Create passage back down from observatory (no key required)
    auto passageDown = std::make_shared<Passage>(
    "Observatory_to_Hilltop",
    "A narrow stairway leading down.",
    observatory.get(),
    hilltop.get()
    );

  // Secret room above the observatory
    Passage::createBasicPassage(observatory.get(), secret_room.get(), "up", true);
    Passage::createBasicPassage(secret_room.get(), observatory.get(), "down", true);


// --- Item Creation Section ---

// Create example items
    auto torch = new Item("torch", "A bright torch that can light up dark places.");
    auto key = new Item("key", "A small brass key with a faded number.");
    auto map = new Item("map", "An old, crumpled map showing part of the mansion.");
    auto rope = new Item("rope", "A sturdy rope, useful for climbing or pulling heavy things.");
    auto shovel = new Item("shovel", "A well-used shovel, perfect for digging.");
    auto vial = new Item("vial", "A glowing vial containing a mysterious liquid.");
    auto telescope = new Item("telescope", "A telescope aimed at the stars.");
    auto orb = new Item("orb", "A glowing orb that pulses softly with energy.");

// Place items into specific rooms
    start->addItem(torch);
    dark_cave->addItem(key);
    observatory->addItem(map);
    forest_path->addItem(rope);
    cave_entrance->addItem(shovel);
    underground_lake->addItem(vial);
    hilltop->addItem(telescope);
    secret_room->addItem(orb);


 // --- Engine Initialization ---

// Initialize the ZOOrkEngine and start the game loop from the start room
    ZOOrkEngine engine(start);

    engine.run(); // Launches the main game loop

    return 0;
}
