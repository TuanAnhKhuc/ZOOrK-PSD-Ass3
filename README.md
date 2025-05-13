# 🕹️ ZOOrk - Text Adventure Game (C++)

<details open>
<summary>🧭 Overview</summary>

**ZOOrk** is a command-line text adventure game implemented in C++.  
It uses object-oriented design and includes key design patterns like the **Command Pattern**, **Singleton**, and **Null Object Pattern**.  
Explore a 10-room world, collect items, and interact with the environment using typed commands in your terminal.

</details>

---

<details>
<summary>🔑 Features</summary>

- 🌍 **10 interconnected rooms**: cave, forest, observatory, secret room, and more  
- 🧱 **Item interaction**: pick up, inspect, and drop items (e.g., `torch`, `map`, `key`, `orb`)  
- 🎒 **Inventory system**: view what you're carrying at any time  
- 🚫 **Safe direction handling** with `NullPassage` — no segmentation faults  
- 💬 **Supported commands**:
  - `go <direction>` (or `n`, `s`, `e`, `w`, `in`, `up`, `down`)  
  - `look`, `look <item>`  
  - `take <item>`, `drop <item>`  
  - `inventory`, `quit`

    <img width="478" alt="Screenshot 2025-05-13 at 20 46 28" src="https://github.com/user-attachments/assets/c253a449-1033-4c18-a657-0adf9f4cda88" />


</details>

---

<details>
<summary>🚀 Build & Run</summary>

```bash
cd build
cmake ..
cmake --build .
./ZOOrk
```

✅ **Requirements**  
- C++17 or later  
- CMake 3.x+  
- macOS/Linux (TTY-compatible terminal recommended)

</details>

---

<details>
<summary>🧪 Example Commands</summary>

```
go north        or: n  
go south        or: s  
go east         or: e  
go west         or: w  
look            or: look <item>  
take <item>  
drop <item>  
inventory  
quit
```

</details>

---

<details>
<summary>🎮 Sample Game Run (Find the Secret Room)</summary>

```
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

</details>

---

<details>
<summary>🧱 Key Implementation Changes</summary>

### 🗂️ `main.cpp`
- Built 10 fully connected rooms  
- Placed unique interactive items in various locations  
- Linked rooms using bidirectional `Passage` objects  

### 🏠 `Room.cpp` / `Room.h`
- Added room inventory system with:
  - `addItem()`, `removeItem()`, `getItem()`  
- Overridden `getPassage()` to return `NullPassage` for invalid directions  

### 👤 `Player.cpp` / `Player.h`
- Implemented player inventory using `std::vector<Item*>`  
- Added:
  - `addItem()`, `removeItem()`, `getInventory()`  

### ⚙️ `ZOOrkEngine.cpp` / `ZOOrkEngine.h`
- Built command handlers:
  - `handleGoCommand()` (with direction alias support: `n`, `e`, etc.)  
  - `handleTakeCommand()`, `handleDropCommand()`  
  - `handleLookCommand()`, `handleInventoryCommand()`, `handleQuitCommand()`  
- Added default error handling for unknown or invalid commands  

### 🚫 `NullPassage.cpp` / `NullPassage.h`
- Implemented **Null Object Pattern** for invalid moves  
- Displays message: `"You can't go that way."`  
- Prevents null pointer dereferencing and crashes  

</details>

---

<details>
<summary>📝 Notes</summary>

- ✅ Built with modern **C++17**  
- 🧩 Fully modular and scalable for more features  
- 🎮 Playable directly in any terminal  
- 🐧 Works on **macOS** and **Linux**  
- 🛠️ Can be extended with puzzles, enemies, or more rooms  

</details>


