#pragma once

#include <SFML/Graphics.hpp>

#include "tile.hpp"

class game
{
private:
    void handleEvents();
    void update();
    void render();
    sf::Clock clock;
    sf::Clock updateTile;
    sf::View view;
    float deltaTime;

    sf::RenderWindow window;
    tile tile;
public:
    game();
    void run();
};