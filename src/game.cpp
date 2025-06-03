#include "game.hpp"
#include <iostream>

game::game()
    : window(sf::VideoMode({800, 600}), "Game of Life"),
      tile(0, 0)
{
    window.setFramerateLimit(60);
    tile.init();
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
    deltaTime = clock.restart().asSeconds();
    tile.update(deltaTime);
    float delta = updateTile.getElapsedTime().asSeconds();
    if (delta >= 1) {
        std::cout << "Do" << std::endl;
        updateTile.restart();
    }
}

void game::render() {
    window.clear(sf::Color::Black);
    tile.draw(window);
    window.display();
}