//
// Created by USER on 16.10.2023.
//

#include "../constants.h"

#ifndef PROJECT_CPP_CHESSBOARDGRID_H
#define PROJECT_CPP_CHESSBOARDGRID_H

class Djikstra;
class BFS;
class Grid {
    friend class Djikstra;
    friend class BFS;
public:
    Grid();
    void createGrid();
    void handleMouseEvents(sf::Event eventHandler);
    void run();
    void drawGrid();
    void drawPath();

private:
    sf::RenderWindow window;
};

#endif //PROJECT_CPP_CHESSBOARDGRID_H
