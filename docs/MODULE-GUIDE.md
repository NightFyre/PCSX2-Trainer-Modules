# Game Module Development Guide

Game Modules extend the functionality of the **PCSX2-Trainer-SDK** for specific titles. Each module provides custom offsets, structures, and helper utilities for a game, allowing developers to build features such as trainers, debugging overlays, or data visualizers with minimal setup.

---

## 📁 Folder Structure

Every module should follow the standardized layout below:

```
template/
│
├── include/
│   ├── template_classes.h     <- Define game-specific classes
│   ├── template_structs.h     <- Define game-specific structs, offsets, and enums
│   └── template_package.h     <- Constants, macros, and utility declarations
│
├── src/
│   └── template_package.cpp   <- Implementation of utility functions
│
├── assets/ (optional)
│   ├── preview.png            <- Optional image (menus, HUDs, etc.)
│   └── notes.txt              <- Memory notes, IDA maps, or analysis dumps
│
└── README.md
```

---

## 🧩 Module Naming

Each module directory should use a **short, clear name** matching the game it supports.
For example:

```
modules/
├── socom2/
├── mgs3/
├── gta_sa/
```

Inside each folder, the file names should follow the same naming pattern as the folder (e.g. `socom2_structs.h`, `socom2_package.cpp`).

---

## ⚙️ Include Integration

Each game module is designed to **self-contain SDK integration** — meaning you only need to include the module’s package header.

The `*_package.h` file automatically includes the core SDK (`CDK.h`), so all necessary types, functions, and utilities are available without extra includes.

Example usage:

```cpp
#include <modules/socom2/include/socom2_package.h>
```

Internally, your module’s package header should end with:

```cpp
#pragma once
#include <CDK.h>
#include "socom2_structs.h"
#include "socom2_classes.h"
```

This ensures the module has full access to the SDK base while keeping integration simple and consistent.

---


## 🧱 Adding Utility Functions

Utility functions should live in `template_package.cpp` and be declared in `template_package.h`.
Example:

```cpp
// template_package.h
namespace template_pkg
{
    bool IsPlayerAlive(uintptr_t playerBase);
}

// template_package.cpp
namespace template_pkg
{
    bool IsPlayerAlive(uintptr_t playerBase)
    {
        return *(uint8_t*)(playerBase + 0x34) > 0;
    }
}
```

---

## 🧠 Structs and Offsets

Define all offsets and in-memory data structures in `template_structs.h`.
Keep offsets grouped and commented for clarity.

```cpp
struct Player
{
    float health;      // 0x00
    float stamina;     // 0x04
    uint32_t ammo;     // 0x08
};
```

You can also use `enum`s for identifying memory regions, states, or flags:

```cpp
enum eGameState
{
    STATE_LOADING,
    STATE_PLAYING,
    STATE_PAUSED
};
```

---

## 🗃️ Optional Assets

Each module may include supporting assets:

* **preview.png** — screenshot of UI, minimap, or menu (optional)
* **notes.txt** — development notes, address mappings, or reverse-engineering notes

These files are not required but help with maintenance and collaboration.

---

## 🧩 Packaging and Usage

Modules are meant to be **plug-and-play** with the Trainer SDK.

When distributing or including a module:

* Ensure include paths are relative to your SDK root
* Maintain consistent naming conventions
* Include a `README.md` describing module usage and setup

Example module README structure:

```
# SOCOM II Module

Provides data structures and offsets for SOCOM II (SLUS_206.24).

## Usage
Include the package header in your trainer:
#include <modules/socom2/include/socom2_package.h>

## Notes
- Player data starts at 0x2050A000
- Map names stored at 0x20480000
```

---

## ✅ Tips for Clean Modules

* Keep all game-specific logic inside the module — not the SDK core.
* Use namespaces to prevent conflicts.
* Comment every major structure and offset group.
* Avoid hardcoding static addresses in implementation; use defines or macros.

---

## 🧱 Template Reference

You can duplicate the `/template` folder to create a new module.
Rename files and identifiers to your target game before adding content.

Example:

```
cp -r template socom2
rename 's/template/socom2/' socom2/include/*
rename 's/template/socom2/' socom2/src/*
```

Then edit all internal identifiers from `template_` → `socom2_`.

---

## 🔗 Integration with SDK

Reference this repository from your main PCSX2-Trainer-SDK:

```markdown
### Game Module SDKs
Extend the SDK with modular game definitions:
[PCSX2-Trainer-Modules](https://github.com/NightFyre/PCSX2-Trainer-Modules)
```

This allows developers to pull both repositories for full environment setup.
