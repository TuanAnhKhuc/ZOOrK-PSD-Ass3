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

</details>

---

<details>
<summary>🔐 New Feature: Locked Door (`Door` Class)</summary>

### 🔐 Description
A new `Door` class has been added to enhance exploration by gating certain areas behind item requirements.  
Players must possess a specific item (e.g., `key`) to open the door.

### 📂 New Files
- `Door.h` – Declares the `Door` class (inherits from `Passage`)
- `Door.cpp` – Implements logic for item-checking traversal

### 🔧 Modified Files
- `main.cpp` – Replaces standard `Passage` from Hilltop → Observatory with a `Door` that requires a `key`
- `Player.h` / `Player.cpp` – Added `hasItem()` method to check inventory
- `Passage.h` / `Passage.cpp` – Added virtual `canTraverse()` and `traverse()` methods for polymorphism
- `ZOOrkEngine.cpp` – Updated `handleGoCommand()` to always call `traverse()`, but only call `enter()` if `canTraverse()` returns true

### 🚪 Door Behavior
- A locked door is placed between **Hilltop** and **Observatory**
- Requires the **key** (found in the **Dark Cave**) to unlock
- Shows helpful message if player lacks the item:
  ```
  The door is locked. You need a key to pass.
  ```

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
go up/down      or: u/d  
go in/out
look            or: look <item>  
take <item>  
drop <item>  
inventory  
quit
```

</details>

---

<details>
<summary>🎮 Sample Game Run (Find the Secret Room with Locked Door)</summary>

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

### 🔐 Locked Door Interaction

```
> go up
The door is locked. You need a key to pass.

> take key
> go up
You unlock the door using the key and pass through.
```

</details>

---

<details>
<summary>🧱 Key Implementation Changes</summary>

### 🗂️ `main.cpp`
- Built 10 fully connected rooms  
- Placed interactive items in various locations  
- Introduced locked `Door` passage between hilltop and observatory

### 🏠 `Room.cpp` / `Room.h`
- Room inventory system (`addItem()`, `removeItem()`, `getItem()`)  
- Overridden `getPassage()` to safely return a `NullPassage`  

### 👤 `Player.cpp` / `Player.h`
- Singleton player with inventory using `std::vector<Item*>`  
- `hasItem()` now allows doors to validate key possession  

### ⚙️ `ZOOrkEngine.cpp` / `ZOOrkEngine.h`
- Enhanced `handleGoCommand()` to always call `traverse()`, and conditionally `enter()`  
- Direction aliasing for commands like `n`, `s`, `u`, `d`

### 🧱 `Passage.cpp` / `Passage.h`
- Added polymorphic `canTraverse()` and `traverse()` methods  
- Base behavior allows free traversal; `Door` overrides it

### 🚫 `NullPassage.cpp` / `NullPassage.h`
- Implements Null Object Pattern for invalid directions  
- Prevents crashes due to null pointer access

</details>

---

<details>
<summary>📝 Notes</summary>

- ✅ Built using modern **C++17**  
- 🔄 Easily extensible: NPCs, puzzles, achievements  
- 🕹️ Modular and stable for future features  
- 💡 Sample extensibility ideas:
  - Talk to NPCs (`talk <name>`)
  - Use/activate items
  - Status tags like `cursed`, `flying`, `brave`
  - Timed puzzles or combat system

</details>