#if !defined(NODE_H)
#define NODE_H

#define NUM_CELLS 20
#define CELL_SIZE (600 / NUM_CELLS)

#include <SFML/Graphics.hpp>

class Cell : public sf::Drawable, public sf::Transformable
{
public:
    enum CellType
    {
        Empty,
        Wall,
        Start,
        Visiting,
        Path,
        End,
    };

public:
    Cell();

    CellType get_type() const;
    void set_type(CellType type);
    void set_parent(Cell *parent);
    Cell *get_parent() const;

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override final;

private:
    sf::RectangleShape sprite;
    CellType type;
    Cell *parent;
};

#endif // NODE_H
