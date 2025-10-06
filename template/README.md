# 🎮 Template Game Module

### *Base structure for creating new PCSX2 Trainer Modules*

---

## 🧩 Overview

This is the **template** for creating new Game Modules for the [PCSX2-Trainer-SDK](https://github.com/NightFyre/PCSX2-Trainer-SDK).

Each module provides game-specific definitions, structures, and helper functions used to build or extend trainers.

---

## 📁 Folder Structure

```
template/
│
├── include/
│   ├── template_classes.h     <- Define game-specific classes
│   ├── template_structs.h     <- Define game-specific structs , offsets and enums
│   └── template_package.h     <- constants , macros and utility functions
│
├── src/
│   └── template_package.cpp     <- implementation of utility functions
│
├── assets/ (optional)
│   ├── preview.png            <- Optional visual (menu, map, etc.)
│   └── notes.txt              <- Memory notes, IDA maps, etc.
│
└── README.md
```

---

## 🧠 Getting Started

1. **Copy the folder** and rename it to your target game:

   ```
   modules/YourGameName/
   ```
2. **Update header filenames** and replace all `template_` prefixes.
3. Add your game’s classes, structs, offsets, and utility code.
4. Fill out your module’s `README.md` (example below).

---

## 📝 Example Game README Format

````
# SOCOM 2 Module
### PCSX2 Trainer SDK – Game Extension

🕹️ **Game ID:** SLUS_200.XX  
🧠 **PCSX2 Version:** 1.7.6+  
📦 **Supported SDK:** v1.0.0+

---

### Features
- Player, weapon, and team structure mapping
- Entity iteration and memory synchronization
- Custom hook examples

---

### Usage
```cpp
#include "modules/SOCOM2/include/socom2_package.h"
````

Initialize during trainer load:

```cpp
SOCOM2::Init();
```

---

### Notes

This module provides high-level access to player and world state for SOCOM II.

```

---

## 🧾 License
All modules are distributed under the [MIT License](../../LICENSE).
```
