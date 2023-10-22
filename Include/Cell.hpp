#if !defined(NODE_H)
#define NODE_H

#define NUM_CELLS 60
#define CELL_SIZE (600 / NUM_CELLS )

#include <SFML/Graphics.hpp>

class Cell : public sf::Drawable, public sf::Transformable
{
public:
    enum CellType
    {
        Empty,
        Wall,
        Start,
        End,
        Count
    };

public:
                        Cell();
    
    CellType            get_type() const;
    void                set_type(CellType type);

private:
    virtual void        draw(sf::RenderTarget &target, sf::RenderStates states) const override final;

private:
    sf::RectangleShape  sprite;
    CellType            type;
};

#endif // NODE_H
