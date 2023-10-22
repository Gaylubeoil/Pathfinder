#if !defined(APPLICATION_H)
#define APPLICATION_H

#include "Editor.hpp"

#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <cstdlib>
#include <stdexcept>

class Application : private sf::NonCopyable
{
public:
    Application();
    ~Application() = default;

    void run();

private:
    void update(sf::Time dt);
    void render();
    void process_input();

    void update_statistics(sf::Time dt);

private:
    static const sf::Time TIME_PER_FRAME;
    sf::RenderWindow window;
    sf::Font font;

    Editor editor;

    sf::Text statistics_text;
    sf::Time statistics_update_time;
    std::size_t statistics_num_frames;
};

#endif // APPLICATION_H
