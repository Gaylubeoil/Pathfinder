# BFS Pathfinder with SFML

![Pathfinder Demo](pathfinder_demo.gif)

## Overview

This is a custom Breadth-First Search (BFS) pathfinder application built using SFML. It allows you to create and visualize grid mazes, place start and end points, and find the shortest path between them using the BFS algorithm. Additionally, it calculates and displays the time the algorithm took and the number of steps taken to find the path.

## Features

- **Maze Creation**: Draw your custom mazes with walls and empty spaces.
- **Start and End Points**: Place the starting and ending points in the maze.
- **Breadth-First Search**: Find the shortest path using the BFS algorithm.
- **Path Visualization**: See the path between start and end points highlighted.
- **Timing and Step Count**: Get information on the time taken for the algorithm and the number of steps.

## Requirements

- C++ compiler (e.g., g++)
- SFML library (Simple and Fast Multimedia Library)

## Installation

1. Clone the repository:

    ```shell
    git clone https://github.com/yourusername/pathfinder-sfml.git
    ```

2. Build the application:

    ```shell
    g++ *.cpp -o pathfinder -lsfml-graphics -lsfml-window -lsfml-system
    ```

3. Run the application:

    ```shell
    ./pathfinder
    ```
4. Alternatively just compile using the CMakeLists.txt
   
## Usage

- **Left Mouse Button**: Draw walls and paths on the grid.
- **Right Mouse Button**: Erase walls and paths on the grid.
- **S Key**: Place the starting point.
- **E Key**: Place the ending point.
- **Spacebar**: Start the BFS pathfinding algorithm.
- **R Key**: Restert the grid (use it after each new search).

## Screenshots

![bfs_img](https://github.com/Gaylubeoil/Pathfinder/assets/92313524/ede22c04-0e1f-4215-8548-87d6b650fd90)


