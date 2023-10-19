//
// Created by USER on 16.10.2023.
//
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <vector>


#ifndef PROJECT_CPP_CHESSBOARDGRID_H
#define PROJECT_CPP_CHESSBOARDGRID_H

#define gridSize 50.f
#define mapSizeX 20
#define mapSizeY 20
#define windowSize 900

class ChessboardGrid {
public:
    ChessboardGrid();
    void createGrid();
    void handleMouseEvents(sf::Event eventHandler);
    void run();
    void drawGrid();

private:
    sf::RenderWindow window;
    sf::RectangleShape tileMap[mapSizeX][mapSizeY];
};

#endif //PROJECT_CPP_CHESSBOARDGRID_H
