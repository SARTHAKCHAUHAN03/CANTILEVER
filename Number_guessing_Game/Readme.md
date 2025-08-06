# 🎮 Number Guessing Game in C++

This is a simple console-based number guessing game written in **C++**. The program generates a random number between a defined range (default: 1 to 100), and the player has a limited number of attempts (default: 5) to guess the correct number.

---

## 🧠 Game Rules

- The player has **5 attempts** to guess the number.
- The number is randomly generated between **1 and 100**.
- After each guess, the game gives feedback:
  - "Too high! Try lower" if the guess is too high.
  - "Too low! Try higher" if the guess is too low.
- The game ends when:
  - The correct number is guessed.
  - The number of attempts runs out.

---

## 🛠️ How to Run

1. **Compile the program:**

   ```bash
   g++ -o guessing_game main.cpp

