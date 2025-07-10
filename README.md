# Snake and Ladder Console Game

A classic Snake and Ladder game implemented in C++ for the console. Challenge your friends in this exciting board game where luck of the dice determines your fate!

## Table of Contents

* [Description](#description)

* [Features](#features)

* [How to Play](#how-to-play)

* [Game Rules](#game-rules)

* [Snakes and Ladders](#snakes-and-ladders)

* [Technologies Used](#technologies-used)

* [Setup/Installation](#setupinstallation)

* [Contributing](#contributing)

* [License](#license)

## Description

This project is a console-based implementation of the popular board game "Snake and Ladder." Two players take turns rolling a dice, moving their respective tokens on a 100-square board. The objective is to be the first player to reach square 100. Be careful of snakes that send you down, and look out for ladders that give you a boost!

## Features

* **Two-Player Gameplay:** Compete against a friend.

* **Dice Roll Mechanism:** Random dice rolls determine movement.

* **Snake and Ladder Logic:** Automatic movement up ladders and down snakes.

* **Win Condition:** First player to reach 100 wins.

* **Player Naming:** Customize player names.

* **Win Streak Tracking:** Keeps track of the longest winning streak for each player.

* **Console-Based UI:** Simple and interactive text-based interface.

* **Play Again Option:** Easily restart the game after a match.

## How to Play

1. **Run the Executable:** Compile and run the `main.cpp` file.

2. **Enter Player Names:** You will be prompted to enter names for Player 1 and Player 2.

3. **Roll the Dice:** Press any key when prompted to roll the dice for your turn.

4. **Move Your Token:** Your token will automatically move based on the dice roll.

   * If you land on a square with a **ladder's base**, you will move up to its top.

   * If you land on a **snake's head**, you will slide down to its tail.

5. **Reach 100:** The first player to land exactly on square 100 wins the game. If you roll a number that takes you beyond 100, you stay at your current position.

6. **Play Again:** After a game concludes, you can choose to play another round.

## Game Rules

* Players start at position 0 (off the board) and need to roll a 1 to enter the board at position 1.

* If a player rolls a 6, they get an extra turn.

* If a player rolls three consecutive 6s, their turn is forfeited, and their position remains unchanged.

* If a player's move takes them beyond square 100, they remain at their current position and must roll the exact number needed to reach 100 on their next turn(s).

## Snakes and Ladders

Here are the specific positions for snakes and ladders implemented in the game:

**Ladders (Move Up):**

* 5 to 13

* 9 to 31

* 18 to 37

* 28 to 84

* 38 to 57

* 51 to 72

* 62 to 81

* 71 to 92

**Snakes (Move Down):**

* 17 to 7

* 52 to 29

* 64 to 60

* 87 to 24

* 93 to 73

* 95 to 75

* 99 to 78

## Technologies Used

* **C++:** The core programming language.

* **Standard C++ Libraries:** `iostream`, `iomanip`, `string`, `cstdlib`, `thread`.

* **Windows.h:** Used for console-specific functionalities like `SetConsoleTextAttribute` for colored output and `Sleep` (implicitly via `this_thread::sleep_for`) and `GetStdHandle`.

* **Conio.h:** Used for `_getch()` (aliased as `getch()`) for non-buffered character input.

## Setup/Installation

To compile and run this game, you will need a C++ compiler (like g++).

1. **Save the Code:** Save the provided C++ code as `snake_ladder.cpp` (or any `.cpp` extension).

2. **Compile:** Open your terminal or command prompt and navigate to the directory where you saved the file. Compile the code using a C++ compiler:

   ```
   g++ snake_ladder.cpp -o snake_ladder.exe -std=c++11
   
   ```

   *Note: The `-std=c++11` flag is important for `this_thread::sleep_for`.*

3. **Run:** Execute the compiled program:

   ```
   ./snake_ladder.exe
   
   ```

## Contributing

Contributions are welcome! If you have suggestions for improvements or new features, feel free to:

1. Fork the repository.

2. Create a new branch (`git checkout -b feature/YourFeature`).

3. Make your changes.

4. Commit your changes (`git commit -m 'Add some feature'`).

5. Push to the branch (`git push origin feature/YourFeature`).

6. Open a Pull Request.

## License

This project is open-source and available under the [MIT License](#LICENSE.md).
