//
// Created by USER on 16.10.2023.
//
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <vector>


#ifndef PROJECT_CPP_CHESSBOARDGRID_H
#define PROJECT_CPP_CHESSBOARDGRID_H


class ChessboardGrid {
public:
    ChessboardGrid(int mapSize);
    void createGrid();
    void handleMouseEvents();
    void run();
    void drawGrid();

private:
    sf::RenderWindow window;
    int mapSize;
    float gridSize = 50.f;
    std::vector<std::vector<sf::RectangleShape>> tileMap;
    std::vector<sf::RectangleShape> tileRow;

};

#endif //PROJECT_CPP_CHESSBOARDGRID_H

/**
 * DESCRIPTION
 * Description:
The ChessboardGrid class represents a grid resembling a chessboard in a graphical window using the Simple and Fast Multimedia Library (SFML).
 It provides the functionality to create and display a checkerboard pattern with alternating colors.
 */
