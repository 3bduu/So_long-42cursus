# So_Long - 42 Network Project

This project is part of the 42 Network curriculum and focuses on creating a 2D game using the MinilibX graphics library. The purpose of this project is to implement a game where the player must navigate through a map while collecting items and avoiding obstacles.

# Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [GameControls](#gameControls)
- [MapFormat](#mapFormat)
- [Contributing](#contributing)

## Introduction
The So_Long project involves creating a game where the player must navigate through a map filled with walls, collectibles, and an exit. The player's objective is to collect all the items and reach the exit while avoiding obstacles. The game provides a visual interface using the MinilibX library, allowing the player to interact with the game through keyboard inputs.

## Installation
To install and run So_Long, follow these steps:

Clone the repository:
```
git clone https://github.com/3bduu/So_long-42cursus.git
```
Navigate to the project directory:
```
cd so_long
```
Compile the source code by running the Makefile:
```
make
```
The compilation process will generate an executable named so_long.

Run the game using the following command:
```
./so_long path_to_map
```
Replace path_to_map with the path to the map file you want to use for the game.

## Usage
After running the game with the appropriate map file, the game window will open, displaying the game interface. Use the game controls to navigate through the map, collect items, and reach the exit.

## GameControls
The following keyboard controls are available for playing the game:

* W or ↑: Move the player character up.
* A or ←: Move the player character left.
* S or ↓: Move the player character down.
* D or →: Move the player character right.
* ESC: Close the game window and exit the game.
## MapFormat

The game map is provided in a plain text file with a .ber extension. The map file specifies the layout of the game world, including the player's starting position, walls, collectibles, and the exit. Here is an example of the map format:
```
111111
100101
121001
1000E1
111111
```
* 1: Wall
* 0: Empty space
* P: Player's starting position
* E: Exit
* C: Collectible item
You can create your own custom maps by following the above format. Ensure that the map is valid and contains at least one player position, one exit, and some collectibles.

## Contributing
Contributions to the project are welcome. If you encounter any issues or have suggestions for improvements, please open an issue or submit a pull request.
