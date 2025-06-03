#include "game.hpp"
#include <iostream>

game::game()
    : window(sf::VideoMode({800, 600}), "Game of Life"),
      tile(0, 0),
      view({0,0}, sf::Vector2f(window.getSize()))
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
        if (event->is<sf::Event::Resized>()) {
            window.setView(view);
        }
    }
}


void game::update() {
    view.setSize(sf::Vector2f(window.getSize()));
    deltaTime = clock.restart().asSeconds();
    float delta = updateTile.getElapsedTime().asSeconds();
    if (delta >= 1) {
        std::cout << "Do" << std::endl;
        updateTile.restart();
        tile.update();
    }

    float speed = 200.0f * deltaTime; // Скорость движения камеры

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        view.move({0, -speed});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        view.move({0, speed});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        view.move({-speed, 0});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        view.move({speed, 0});
    }

    window.setView(view);

}


void game::render() {
    window.clear(sf::Color::Black);
    tile.draw(window);
    window.display();
}
