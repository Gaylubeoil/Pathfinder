#include "Application.hpp"
#include "Utility.hpp"

Application::Application()
    : window(sf::VideoMode(800, 600), "Pathfinder", sf::Style::Close),
      statistics_text(),
      editor(window),
      statistics_update_time(),
      statistics_num_frames(0)
{
    font.loadFromFile("../Fonts/Sansation.ttf");
    editor.set_font(&font);

    statistics_text.setFont(font);
    statistics_text.setCharacterSize(10);
    statistics_text.setPosition(760, 5);
    window.setKeyRepeatEnabled(false);
}

const sf::Time Application::TIME_PER_FRAME = sf::seconds(1.f / 60.f);
void Application::run()
{
    sf::Clock clock;
    sf::Time time_since_last_update = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        time_since_last_update += elapsed;
        while (time_since_last_update > TIME_PER_FRAME)
        {
            time_since_last_update -= TIME_PER_FRAME;
            process_input();
            update(TIME_PER_FRAME);
        }
        render();
        update_statistics(elapsed);
    }
}

void Application::update(sf::Time dt)
{
    editor.update(dt);
}

void Application::render()
{
    window.clear();

    editor.render(window);

    window.setView(window.getDefaultView());
    window.draw(statistics_text);
    window.display();
}

void Application::process_input()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        editor.handle_event(event);
        if (event.type == sf::Event::Closed ||
            event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            window.close();
    }
}

void Application::update_statistics(sf::Time dt)
{
    statistics_update_time += dt;
    statistics_num_frames += 1;

    if (statistics_update_time >= sf::seconds(1.f))
    {
        statistics_text.setString("FPS: " + to_string(statistics_num_frames));

        statistics_update_time -= sf::seconds(1.f);
        statistics_num_frames = 0;
    }
}