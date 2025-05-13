# 🕹️ ZOOrk - Text Adventure Game (C++)

## 🧭 Overview

ZOOrk is a command-line text adventure game implemented in C++. It uses object-oriented design and implements key design patterns such as the Command Pattern, Singleton, and Null Object Pattern. Players can explore a 10-room world, collect items, and interact with the environment using typed commands.

---

## 🔑 Features

- 🌍 **10 interconnected rooms** including a cave, forest, observatory, and secret room
- 🧱 **Item interaction**: Pick up, inspect, and drop items (e.g., torch, map, key, orb)
- 🎒 **Inventory system**: See what you're carrying at any time
- 🚫 **Invalid direction handling** via `NullPassage` (no segmentation faults)
- 💬 **Simple commands**: Use `go`, `look`, `take`, `drop`, `inventory`, `quit`

---

## 🚀 Build & Run

```bash
cd build
cmake ..
cmake --build .
./ZOOrk
```

✅ Requires C++17+ and CMake 3.x  
Tested on macOS with TTY-compatible terminal

---

## 🧪 Commands to Try

```
go north / n
look / look <item>
take <item>
drop <item>
inventory
quit
```

---

## 🧪 Sample Game Run (Reach the Secret Room)

```plaintext
You are standing in an open field west of a white house...

> take torch
> go south
> go east
> go east
> take rope
> go south
> take shovel
> go in
> take key
> go down
> take vial
> go up
> go up
> go north
> go west
> go north
> take telescope
> go up
> take map
> go down
You have discovered a secret room hidden beneath the observatory.

> look orb
A glowing orb that pulses softly with energy.

> take orb
> inventory
You are carrying:
- torch
- rope
- shovel
- key
- vial
- map
- orb
```

---

## 🧱 Key Implementation Changes

### `main.cpp`
- Created 10 interconnected rooms
- Added and distributed all interactive items
- Linked rooms via bidirectional `Passage` objects

### `Room.cpp / Room.h`
- Added support for `items` list
- Added `getItem()`, `addItem()`, `removeItem()`, and `getObject()`
- Overridden `getPassage()` to return `NullPassage` for invalid directions

### `Player.cpp / Player.h`
- Implemented inventory system using `std::vector<Item*>`
- Added methods: `addItem()`, `removeItem()`, `getItem()`, and `getInventory()`

### `ZOOrkEngine.cpp / ZOOrkEngine.h`
- Implemented command handlers:
  - `handleGoCommand()`
  - `handleTakeCommand()`
  - `handleDropCommand()`
  - `handleLookCommand()`
  - `handleInventoryCommand()`
  - `handleQuitCommand()`
- Refactored direction handling to support aliases (`n`, `s`, etc.)
- Added feedback for unrecognized commands and invalid directions

### `NullPassage.cpp / NullPassage.h`
- Implemented **Null Object Pattern**
- Prevents crashes on invalid moves
- Displays friendly message: `"You can't go that way."`

---

## 📝 Notes

- Uses modern C++17 features
- Designed for stability and scalability
- Fully playable through a terminal
- Compatible with Linux/macOS

---


