//
// Created by USER on 16.10.2023.
//

#include "../constants.h"

#ifndef PROJECT_CPP_CHESSBOARDGRID_H
#define PROJECT_CPP_CHESSBOARDGRID_H

class Djikstra;

class Grid {
    friend class Djikstra;
public:
    Grid();
    void createGrid();
    void handleMouseEvents(sf::Event eventHandler);
    void run();
    void drawGrid();

private:
    sf::RenderWindow window;
    sf::RectangleShape tileMap[mapSizeX][mapSizeY];
};

#endif //PROJECT_CPP_CHESSBOARDGRID_H
