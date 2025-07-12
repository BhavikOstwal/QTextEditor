# QTextEditor

**QTextEditor** is a lightweight, custom-built text editor implemented in C++ using Qt. It features a core gap buffer data structure for efficient text manipulation and a custom GUI built with Qt Widgets for responsive rendering.

This project serves as a foundational step toward building a modern, extensible text editor with accurate cursor handling, clean rendering, and a responsive user interface.

---

## Features

* Custom **gap buffer** implementation for efficient insertions and deletions
* Basic keyboard navigation (left, right, insert, delete)
* Smooth cursor rendering with blinking support
* Multi-line text rendering using `QPainter`
* Minimal UI built on `QWidget` and `QPainter`
* Designed for extensibility and clean architecture

---

## Architecture Overview

* `TextEditor`: Core logic implementing the gap buffer, cursor movement, and text operations
* `EditorWidget`: GUI layer handling painting, keyboard input, and rendering logic
* `main.cpp`: Initializes the application window and launches the editor

---

## Project Structure

```

QTextEditor/
├── Editor.h            # Gap buffer interface
├── Editor.cpp          # Core logic implementation
├── EditorUI.h          # Qt Widget interface
├── EditorUI.cpp        # UI logic and rendering
├── main.cpp            # Application entry point
```

---

## Build Instructions

Ensure you have **Qt 6** and a C++ compiler installed.

### Using CMake (Recommended)

```bash
mkdir build
cd build
cmake ..
make
./QTextEditor
```

### Using qmake (Qt projects)

If you're using `.pro` file:

```bash
qmake
make
./QTextEditor
```

---

## Dependencies

* Qt Core
* Qt Widgets
* C++17 or higher (recommended)

---
