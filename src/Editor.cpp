#include "Editor.hpp"
#include "Utility.hpp"

#include <cmath>

Editor::Editor(sf::RenderWindow &target)
    : target(target), maze(), clock(),
      completion_time(0), valid_time(false), title(), completion_text(), steps_text()
{
    title.setString("Breadth First search");
    title.setCharacterSize(14);
    title.setPosition(605, 30);

    completion_text.setPosition(605, 130);
    completion_text.setCharacterSize(12);

    steps_text.setPosition(605, 210);
    steps_text.setCharacterSize(12);
}

void Editor::update_texts()
{
    completion_text.setString("Completion took " + to_string(completion_time) + " seconds.");

    if (maze.get_steps() != 0)
        steps_text.setString("End node is " + to_string(maze.get_steps()) + " cells away.");
    else
        steps_text.setString("End node can't be reached. ");
}

void Editor::update(sf::Time dt)
{
    update_texts();
    handle_mouseclick();

    maze.update(dt);
    if (maze.finished() && valid_time)
    {
        valid_time = false;
        completion_time = clock.restart().asSeconds();
    }
}

void Editor::set_font(sf::Font *font)
{
    title.setFont(*font);
    completion_text.setFont(*font);
    steps_text.setFont(*font);
}

void Editor::render_texts(sf::RenderTarget &target)
{
    target.draw(title);
    target.draw(completion_text);
    target.draw(steps_text);
}

void Editor::render(sf::RenderTarget &target)
{
    render_texts(target);
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
        set_cell_state(Cell::Wall);
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        set_cell_state(Cell::Empty);
}

void Editor::handle_keyboard_click(sf::Event ev)
{
    if (ev.key.code == sf::Keyboard::S)
        set_cell_state(Cell::Start);
    else if (ev.key.code == sf::Keyboard::E)
        set_cell_state(Cell::End);
    else if (ev.key.code == sf::Keyboard::Space)
        maze.start();
    else if (ev.key.code == sf::Keyboard::R)
    {
        valid_time = true;
        maze.reset();
        clock.restart();
    }
}

bool Editor::valid_mouse_pos(const sf::Vector2i &pos) const
{
    if (pos.x < 0 || pos.x > 600)
        return false;
    if (pos.y < 0 || pos.y > 600)
        return false;
    return true;
}

void Editor::set_cell_state(Cell::CellType type)
{
    sf::Vector2i pos = sf::Mouse::getPosition(target);
    if (valid_mouse_pos(pos))
    {
        int x = std::floor(pos.x / CELL_SIZE);
        int y = std::floor(pos.y / CELL_SIZE);
        Cell &c = maze.get_cell(x, y);

        if (!(type == Cell::Wall && (c.get_type() == Cell::Start || c.get_type() == Cell::End)))
            c.set_type(type);

        if (type == Cell::Start)
            maze.set_start(c);
        else if (type == Cell::End)
            maze.set_end(c);
    }
}