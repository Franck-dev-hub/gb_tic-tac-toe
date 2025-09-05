# 🎮 Game Boy - Tic Tac Toe

[![Language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)](#)
[![GBDK-2020](https://img.shields.io/badge/GBDK-2020-0a7?style=for-the-badge)](https://github.com/gbdk-2020/gbdk-2020)
[![Emulator: SameBoy](https://img.shields.io/badge/Emulator-SameBoy-1f6feb?style=for-the-badge)](https://sameboy.github.io/)
[![Platform](https://img.shields.io/badge/Platform-Game%20Boy-9cf?style=for-the-badge)](#)
[![Build](https://img.shields.io/badge/Build-make-lightgrey?style=for-the-badge)](#)

> A simple **Tic Tac Toe** game written in **C** for the **Nintendo Game Boy**, inspired by [flozz's tutorial](#-acknowledgments).

---

## 🚀 Getting Started

### ✅ Prerequisites
- [lcc](https://gbdk-2020.github.io/gbdk-2020/docs/api/docs_getting_started.html) compiler for Game Boy.
- [GBDK-2020](https://github.com/gbdk-2020/gbdk-2020).
- [SameBoy](https://sameboy.github.io/) emulator.
  _Tested on **Arch Linux**._

### 📥 Installation & Run
1. Clone the repository:
   ```bash
   git clone https://github.com/Franck-dev-hub/gb_tic-tac-toe.git
   cd gb_tic-tac-toe
   ```
2. Build & run:
   ```bash
   make exec
   ```

---

## 🕹️ Gameplay & Controls
- Classic 3×3 Tic Tac Toe.
- D-Pad to move the cursor.
- **A** to place a mark.
- **Start** to start the game.

---

## 📁 Project Structure
```
├── Makefile
├── README.md
├── game.c
├── game.h
├── helpers.c
├── helpers.h
├── main.c
├── screen_title.c
└── screen_title.h
```

---

## 🧪 Make Targets
```Makefile
make            -> Build project
make format     -> Format code synthax
make check      -> Code checker
make check-all  -> Format code + check it
make clean      -> Remove objects
make fclean     -> Remove objects + executable
make re         -> Clean and Rebuild
make exec       -> Compile & execute game
make help       -> Display help
```

---

## ❓ Help
If you encounter issues:
- Ensure `lcc`, `gbdk-2020`, and `sameboy` are correctly installed.
- Open an issue or check the code for hints, I'll add more informations if needed.

---

## 💖 Acknowledgments
- [flozz](https://github.com/flozz/) for this great [tutorial](https://blog.flozz.fr/2018/10/29/developpement-gameboy-3-projet-1-tic-tac-toe/).
