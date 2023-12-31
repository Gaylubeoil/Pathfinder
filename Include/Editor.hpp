#if !defined(EDITOR_H)
#define EDITOR_H

#include "Maze.hpp"

class Editor
{
public:
    Editor(sf::RenderWindow &target);
    ~Editor() = default;

    void set_font(sf::Font *font);

    void update(sf::Time dt);
    void render(sf::RenderTarget &target);
    void handle_event(sf::Event ev);

private:
    void handle_mouseclick();
    void handle_keyboard_click(sf::Event ev);

    void update_texts();
    void render_texts(sf::RenderTarget &target);

    // @brief  Tells us whether or not the mouse is within the maze's size.
    bool valid_mouse_pos(const sf::Vector2i &pos) const;

    void set_cell_state(Cell::CellType type);

private:
    sf::RenderWindow &target;

    Maze maze;

    sf::Clock clock;
    float completion_time;
    bool valid_time;

    sf::Text title;
    sf::Text completion_text;
    sf::Text steps_text;
};

#endif // EDITOR_H
