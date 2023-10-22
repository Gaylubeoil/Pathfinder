#include "Editor.hpp"

#include <cmath>

Editor::Editor(sf::RenderWindow &target) : maze(), target(target) {}

void Editor::update(sf::Time dt)
{
    handle_mouseclick();
    maze.update(dt);
}

void Editor::render(sf::RenderTarget &target)
{
    maze.render(target);
}

void Editor::handle_event(sf::Event ev)
{
    if (ev.type == sf::Event::KeyPressed)
        handle_keyboard_click(ev);
}

void Editor::handle_mouseclick()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i pos = sf::Mouse::getPosition(target);
        if (valid_mouse_pos(pos))
        {
            int x = std::floor(pos.x / CELL_SIZE);
            int y = std::floor(pos.y / CELL_SIZE);
            maze.get_cell(x, y).set_type(Cell::Wall);
        }
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        sf::Vector2i pos = sf::Mouse::getPosition(target);
        if (valid_mouse_pos(pos))
        {
            int x = std::floor(pos.x / CELL_SIZE);
            int y = std::floor(pos.y / CELL_SIZE);
            maze.get_cell(x, y).set_type(Cell::Empty);
        }
    }
}

void Editor::handle_keyboard_click(sf::Event ev)
{
}

bool Editor::valid_mouse_pos(const sf::Vector2i &pos) const
{
    if (pos.x < 0 || pos.x > 600)
        return false;
    if (pos.y < 0 || pos.y > 600)
        return false;
    return true;
}