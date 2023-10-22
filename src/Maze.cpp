#include "Maze.hpp"

Maze::Maze()
    : cells()
{

    initialize_maze();
}

void Maze::initialize_maze()
{
    for (std::size_t x = 0; x < NUM_CELLS; ++x)
        for (std::size_t y = 0; y < NUM_CELLS; ++y)
            cells[x][y].setPosition(x * CELL_SIZE + 1, y * CELL_SIZE + 1);
}

Cell &Maze::get_cell(int x, int y)
{
    return cells[x][y];
}

void Maze::update(sf::Time dt)
{
}

void Maze::render(sf::RenderTarget &target)
{
    for (std::size_t x = 0; x < NUM_CELLS; ++x)
        for (std::size_t y = 0; y < NUM_CELLS; ++y)
            target.draw(cells[x][y]);
}
