#include "Cell.hpp"

sf::Color get_color(Cell::CellType type)
{
    switch (type)
    {
    case Cell::Empty:
        return sf::Color::White;
    case Cell::Wall:
        return sf::Color::Red;
    case Cell::Start:
        return sf::Color::Green;
    case Cell::End:
        return sf::Color::Yellow;
    default:
        return sf::Color::Transparent;
    }
}

Cell::Cell() : sprite(), type(Cell::Empty)
{
    sprite.setSize(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    sprite.setFillColor(get_color(type));
    sprite.setOutlineThickness(1.f);
    sprite.setOutlineColor(sf::Color::Black);
}

Cell::CellType Cell::get_type() const { return type; }
void Cell::set_type(CellType type)
{
    this->type = type;
    sprite.setFillColor(get_color(type));
}

void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(sprite, states);
}