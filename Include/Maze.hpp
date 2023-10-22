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
    ~Maze();

    void update(sf::Time dt);
    void render(sf::RenderTarget &target);

    Cell &get_cell(int x, int y);

    void start();
    void reset();

    void set_start(Cell &start_cell);
    void set_end(Cell &end_cell);

private:
    void initialize_maze();
    void solve_maze();
    void backtrace();

    sf::Vector2i get_cellpos(const Cell &cell) const;

private:
    std::array<std::array<Cell, NUM_CELLS>, NUM_CELLS> cells;

    Cell *start_cell, *end_cell, *current_path;

    std::queue<Cell *> nodes;

    bool m_solve = false;
    bool path_found = false;
    bool not_solvable = false;

    std::size_t steps = 0;
};

#endif // MAZE_H
