# ZOOrk Project - README (Custom Implementation)

## ✅ Overview

This project is a customized and extended version of the original ZOOrk game. The game is a text-based adventure implemented in C++ using object-oriented principles and design patterns such as the Command Pattern and Singleton.

## ✨ Major Enhancements

The following improvements have been made to the base code:

### 1. **Map Expansion to 10 Rooms**

* Original map with 3 rooms has been extended to **10 unique rooms** including:

  * Start, South of House, Behind House, Forest Path, Cave Entrance
  * Dark Cave, Underground Lake, Hilltop, Observatory, Secret Room
* Each room is connected using two-way `Passage` objects for smooth navigation.

### 2. **Item System Implementation**

* Added `Item` support to rooms and player inventory.
* Rooms now contain unique items such as:

  * `torch`, `key`, `map`, `rope`, `shovel`, `vial`, `telescope`, `orb`
* Players can use commands:

  * `look <item>`: Inspect items
  * `take <item>`: Pick up items from rooms
  * `drop <item>`: Drop items into rooms
  * `inventory`: View carried items

### 3. **Bidirectional Passages**

* Ensured that all rooms are connected with forward and reverse `Passage` objects to prevent getting stuck.

### 4. **Enhanced Room Descriptions**

* Room descriptions have been updated to mention visible items in the environment for better immersion.

## 🔧 Files Modified or Added

### `main.cpp`

* Created 10 rooms with detailed descriptions
* Added items and assigned them to appropriate rooms
* Connected all rooms using bidirectional `Passage` links

### `Room.h / Room.cpp`

* Added support for:

  * `std::vector<Item*> items`
  * `addItem()`, `removeItem()`, `getItem()`, `getObject()`

### `Player.h / Player.cpp`

* Added inventory support:

  * `std::vector<Item*> inventory`
  * `addItem()`, `removeItem()`, `getItem()`, `getInventory()`

### `ZOOrkEngine.h / ZOOrkEngine.cpp`

* Implemented core command handlers:

  * `handleLookCommand()`
  * `handleTakeCommand()`
  * `handleDropCommand()`
  * `handleInventoryCommand()`
* Extended `run()` to support new commands

## 🧪 Commands to Test

* `look` / `look map`
* `take torch`
* `drop key`
* `inventory`
* `go north/south/east/west/up/down`
* `quit`

## 🚀 How to Build and Run

```bash
cd build
cmake ..
cmake --build .
./ZOOrk
```

## 📌 Notes

* Requires C++17 or later
* Compiled and tested on macOS using CMake
* Ensure TTY input works in your terminal for interactive gameplay

---

Made with ❤️ by Tuan Anh Khuc
