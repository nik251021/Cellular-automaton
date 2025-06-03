#include "game.hpp"

game::game()
    : window(sf::VideoMode({800, 600}), "Game of Life"),
      tile(0, 0) // <-- координаты сетки
{
    window.setFramerateLimit(60);
    tile.init(); // Генерация случайного поля
}

void game::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void game::handleEvents() {
    while (std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void game::update() {
    
}

void game::render() {
    window.clear(sf::Color::Black);
    tile.draw(window);
    window.display();
}