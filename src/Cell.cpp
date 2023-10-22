#include "Cell.hpp"

sf::Color to_color(Cell::CellType type)
{
    switch (type)
    {
    case Cell::Empty:
        return sf::Color(200, 200, 200);
    case Cell::Wall:
        return sf::Color::Blue;
    case Cell::Start:
        return sf::Color::Green;
    case Cell::End:
        return sf::Color::Yellow;
    case Cell::Visiting:
        return sf::Color::Magenta;
    case Cell::Path:
        return sf::Color::Black;
    default:
        return sf::Color::Transparent;
    }
}

Cell::Cell() : sprite(), type(Cell::Empty), parent(nullptr)
{
    sprite.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    sprite.setFillColor(to_color(type));
    sprite.setOutlineThickness(1.f);
    sprite.setOutlineColor(sf::Color::Black);
}

Cell::CellType Cell::get_type() const { return type; }
void Cell::set_type(CellType type)
{
    this->type = type;
    sprite.setFillColor(to_color(type));
}

void Cell::set_parent(Cell *parent)
{
    this->parent = parent;
}

Cell *Cell::get_parent() const
{
    return parent;
}

void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite, states);
}