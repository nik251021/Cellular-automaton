#include "tile.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

tile::tile(int x, int y) {
    tilex = x;
    tiley = y;
    grid.resize(gridHeight, std::vector<int>(gridWidth, 0));
    std::srand(std::time(nullptr));
}

void tile::init() {
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            grid[y][x] = (std::rand() % 100 < 30) ? 1 : 0;
            
        }
    }
}

void tile::update(float dt) {
    
}

void tile::draw(sf::RenderWindow& window) {
    const float SquareSize = 10.0f;
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            if (grid[y][x] == 1) {
                sf::RectangleShape Square(sf::Vector2f(SquareSize - 1, SquareSize - 1));
                Square.setPosition({tilex + x * SquareSize, tiley + y * SquareSize});
                Square.setFillColor(sf::Color::Green);
                window.draw(Square);
            }
        }
    }
}
