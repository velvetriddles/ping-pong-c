# Pong Game in C

This repository contains two implementations of the classic Pong game in C: one using the ncurses library for a graphical interface and the other using the standard library for a text-based interface.

## Description

Pong is a table tennis-themed arcade sports video game featuring simple two-dimensional graphics. The aim is to defeat the opponent by earning a higher score. The game is played on a rectangular field with paddles and a ball. This project includes two versions of the game:

1. **Interactive Pong with ncurses (`pong_interactive.c`)**: This version uses the ncurses library to provide a graphical user interface in the terminal.
2. **Text-based Pong with standard library (`pong.c`)**: This version uses standard input and output to create a simple text-based interface.

## Requirements

- **For ncurses version**:
  - C compiler (e.g., gcc)
  - ncurses library (installable via package manager, e.g., `sudo apt-get install libncurses5-dev libncursesw5-dev`)

- **For standard library version**:
  - C compiler (e.g., gcc)

## Installation and Running

### ncurses Version

1. Clone the repository or download the source code.
2. Navigate to the directory with the source code.
3. Compile the `pong_interactive.c` using gcc:

    ```sh
    gcc -o pong_interactive pong_interactive.c -lncurses
    ```

4. Run the compiled program:

    ```sh
    ./pong_interactive
    ```

### Standard Library Version

1. Clone the repository or download the source code.
2. Navigate to the directory with the source code.
3. Compile the `pong.c` using gcc:

    ```sh
    gcc -o pong pong.c
    ```

4. Run the compiled program:

    ```sh
    ./pong
    ```

## Controls

### ncurses Version

- `k` — Move Player 2's paddle up
- `m` — Move Player 2's paddle down
- `a` — Move Player 1's paddle up
- `z` — Move Player 1's paddle down
- `y` — Quit the game

### Standard Library Version

- `k` — Move Player 2's paddle up
- `m` — Move Player 2's paddle down
- `a` — Move Player 1's paddle up
- `z` — Move Player 1's paddle down
- `y` — Quit the game
- Space — Pause and resume the game

## Game Rules

- The ball bounces off the top and bottom edges of the screen.
- If the ball hits the paddles, it bounces back; if it passes the paddles, the opponent scores a point.
- The first player to reach 21 points wins the game.

## Example Output

### ncurses Version

The game is displayed in the terminal window using graphical characters to represent the paddles and ball.

### Standard Library Version

The game is displayed in the terminal using text characters to represent the paddles and ball. The screen updates after each move to show the current state of the game.

## Contact

If you have any questions or suggestions, please contact me at @velvetriddles.
