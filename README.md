# 🧩 PCSX2 Trainer Modules
### *Game-Specific Extensions for the PCSX2-Trainer-SDK*

[![License](https://img.shields.io/github/license/NightFyre/PCSX2-Trainer-Modules?color=blue)](LICENSE)
[![Contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen)](CONTRIBUTING.md)
[![Made for PCSX2-Trainer-SDK](https://img.shields.io/badge/SDK-PCSX2--Trainer--SDK-red)](https://github.com/NightFyre/PCSX2-Trainer-SDK)

---

## 📖 Overview

This repository contains **official and community-developed Game Module SDKs** for the [PCSX2-Trainer-SDK](https://github.com/NightFyre/PCSX2-Trainer-SDK).

Each module provides **game-specific support** including:

* Memory structures and function mappings
* Entity and weapon data definitions
* Utilities for trainer development and debugging

These modules are designed to be plug-and-play with the SDK — simply include them in your trainer’s source.

---

## 🧠 Using a Game Module

1. Download or clone this repository alongside the main SDK.
2. Include the desired game’s headers in your trainer project.
3. Register the module via the SDK’s module manager (if used).

Example:

```cpp
#include "modules/GameA/include/gameA_package.h"
```

---

## 🏗️ Creating a New Module

1. Copy the `template/` folder (if available).
2. Rename it to your target game (e.g., `SOCOM2/`).
3. Include your game-specific structures, offsets, and helper functions.
4. Document usage and setup instructions in the module’s `README.md`.

When finished, submit a PR to this repository.

---

## 🧾 License

All content is licensed under the [MIT License](LICENSE) unless stated otherwise.

---

## 🌐 Related Repositories

* 🧰 [PCSX2-Trainer-SDK](https://github.com/NightFyre/PCSX2-Trainer-SDK) — the core SDK for trainer development
* 🧩 [PCSX2-Trainer-Modules](https://github.com/NightFyre/PCSX2-Trainer-Modules) — official game module collection

---

## 📁 Repository Structure

```
PCSX2-Trainer-Modules/
│
├── modules/
│   ├── SOCOM2/
│   │   ├── include/
│   │   ├── src/
│   │   ├── assets/
│   │   └── README.md
│   └── MGS3/
│       ├── include/
│       ├── src/
│       ├── assets/
│       └── README.md
│
├── template/
│   ├── include/
│   │   ├── template_classes.h
│   │   ├── template_package.h
│   │   ├── template_structs.h
│   │   └── template_defines.h
│   ├── src/
│   │   └── template_package.cpp
│   ├── assets/
│   │   ├── preview.png
│   │   └── notes.txt
│   └── README.md
│
├── docs/
│   ├── CONTRIBUTING.md
│   ├── MODULE_GUIDE.md
│   └── STRUCTURE_OVERVIEW.md
│
├── .github/
│   ├── ISSUE_TEMPLATE/
│   └── PULL_REQUEST_TEMPLATE.md
│
├── LICENSE
└── README.md
```