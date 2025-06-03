#include "tile.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

tile::tile(int x, int y) {
    tilex = x;
    tiley = y;
    grid.resize(gridHeight, std::vector<int>(gridWidth, 0));
    nextGrid.resize(gridHeight, std::vector<int>(gridWidth, 0)); // ← добавь это!
    std::srand(std::time(nullptr));
}

void tile::init() {
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            grid[y][x] = (std::rand() % 100 < 30) ? 1 : 0;
            
        }
    }
}

void tile::update() {
    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            int aliveNeighbors = 0;

            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue;

                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < gridWidth && ny >= 0 && ny < gridHeight)
                        aliveNeighbors += grid[ny][nx];
                }
            }

            if (grid[y][x] == 1) {
                nextGrid[y][x] = (aliveNeighbors == 2 || aliveNeighbors == 3) ? 1 : 0;
            } else {
                nextGrid[y][x] = (aliveNeighbors == 3) ? 1 : 0;
            }
        }
    }

    grid = nextGrid;
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
