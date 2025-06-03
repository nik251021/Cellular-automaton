#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class tile
{
private:
    int tilex;
    int tiley;
    int gridWidth = 150;
    int gridHeight = 150;
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<int>> nextGrid;

public:
    tile(int x, int y);
    void init();
    int getX();
    int getY();
    void update();
    void draw(sf::RenderWindow& window);
};
