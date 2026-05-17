# 🧮 Math Quiz Game (C++)

A dynamic and interactive command-line Math Quiz Game built using modern C++ concepts. The project focuses on clean code practices, modular design, structure manipulation, and robust logic flow.

---

## 🚀 Features

* Multiple Difficulty Levels: Supports Easy (1-10), Medium (1-50), Hard (10-100), and a dynamically generated Mix level.
* Diverse Operations: Includes Addition, Subtraction, Multiplication, Division (with rounded results using round()), and a completely randomized Mix mode.
* Smart Game Statistics: Tracks the total number of questions, correct/wrong answers, and generates a detailed final score report.
* Interactive UI: Changes terminal screen colors dynamically based on the user's answers (Green for right, Red for wrong with a system alert sound \a).
* Replayability: Allows the user to reset statistics and play multiple rounds seamlessly.

---

## 🛠️ Concepts Applied (Clean Code)

This project was built following strict software engineering principles:
* Enums & Structs: Used to avoid magic numbers and bundle game state data efficiently into a single structured object.
* **Pass by Reference (&):** Applied to pass and modify the game state directly across functions to avoid unnecessary memory duplication and optimize performanceRandomization:n:** Built using srand() and time(NULL) to ensure completely dynamic number generation and unpredictable quiz variationsType Safety & Validation:n:** Handled floating-point precision differences during division tracking and ensured basic input handling.

---

## 💻 How to Run

1. Clone this repository or download the source code.
2. Open the project in any C++ IDE (lVisual Studioio**).
3. Compile and run main.cpp.
