#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class tile
{
private:
    int tilex;
    int tiley;
    int gridWidth = 50;
    int gridHeight = 50;
    std::vector<std::vector<int>> grid;

public:
    tile(int x, int y);
    void init();
    void update();
    void draw(sf::RenderWindow& window);
};
