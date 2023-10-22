#if !defined(MAZE_H)
#define MAZE_H

#include "Cell.hpp"

#include <vector>
#include <map>
#include <array>
#include <queue>
#include <iostream>

class Maze
{

public:
    Maze();
    void update(sf::Time dt);
    void render(sf::RenderTarget &target);

    Cell &get_cell(int x, int y);

private:
    void initialize_maze();

private:
    std::array<std::array<Cell, NUM_CELLS>, NUM_CELLS> cells;
};

#endif // MAZE_H
