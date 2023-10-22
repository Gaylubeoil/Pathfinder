#include "Maze.hpp"

Maze::Maze()
    : cells(), start_cell(nullptr), end_cell(nullptr), current_path(nullptr),
      m_solve(false), path_found(false), not_solvable(false), finish(false),
      steps(0)
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

void Maze::start()
{
    if (!start_cell || !end_cell)
        return;
    if (start_cell->get_type() != Cell::Start || end_cell->get_type() != Cell::End)
        return;

    nodes.push(start_cell);
    m_solve = true;
}

void Maze::solve_maze()
{
    if (path_found)
    {
        backtrace();
        return;
    }

    if (nodes.empty())
    {
        not_solvable = true;
        return;
    }

    if (not_solvable)
    {
        // todo
        m_solve = false;
    }

    Cell *current = nodes.front();
    sf::Vector2i pos = get_cellpos(*current);
    nodes.pop();

    std::vector<std::pair<int, int>> neighbours = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (const auto &pair : neighbours)
    {
        int x = pos.x + pair.first;
        int y = pos.y + pair.second;

        if (x < 0 || x >= NUM_CELLS || y < 0 || y >= NUM_CELLS)
            continue;

        Cell &temp = cells[x][y];
        if (temp.get_type() == Cell::End)
        {
            current_path = current;
            path_found = true;
            finish = true;
            return;
        }
        else if (temp.get_type() == Cell::Empty)
        {
            temp.set_type(Cell::Visiting);
            temp.set_parent(current);
            nodes.push(&temp);
        }
    }
}

void Maze::backtrace()
{
    if (current_path->get_type() != Cell::Start)
    {
        current_path->set_type(Cell::Path);
        current_path = current_path->get_parent();
        steps++;
    }
    else if (current_path->get_type() == Cell::Start)
        m_solve = false;
}
void Maze::update(sf::Time dt)
{
    if (m_solve)
        solve_maze();
}

void Maze::render(sf::RenderTarget &target)
{
    for (std::size_t x = 0; x < NUM_CELLS; ++x)
        for (std::size_t y = 0; y < NUM_CELLS; ++y)
            target.draw(cells[x][y]);
}

void Maze::set_start(Cell &start_cell)
{
    // todo if (m_solve) return;
    if (this->start_cell)
        this->start_cell->set_type(Cell::Empty);
    this->start_cell = &start_cell;
}

void Maze::set_end(Cell &end_cell)
{
    // todo if (m_solve) return;
    if (this->end_cell)
        this->end_cell->set_type(Cell::Empty);
    this->end_cell = &end_cell;
}

void Maze::reset()
{
    for (std::size_t x = 0; x < NUM_CELLS; ++x)
        for (std::size_t y = 0; y < NUM_CELLS; ++y)
        {
            cells[x][y].set_type(Cell::Empty);
            cells[x][y].set_parent(nullptr);
        }

    start_cell = nullptr;
    end_cell = nullptr;
    current_path = nullptr;

    path_found = false;
    not_solvable = false;

    steps = 0;

    while (!nodes.empty())
        nodes.pop();
}

bool Maze::finished() const { return finish; }

std::size_t Maze::get_steps() const
{
    if (finish)
        return steps;
    else
        return 0;
}

sf::Vector2i Maze::get_cellpos(const Cell &cell) const
{
    sf::Vector2i pos = static_cast<sf::Vector2i>(cell.getPosition());
    return pos /= CELL_SIZE;
}

Maze::~Maze()
{
}