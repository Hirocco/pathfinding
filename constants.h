//
// Created by USER on 19.10.2023.
//

#ifndef PROJECT_CPP_CONSTANTS_H
#define PROJECT_CPP_CONSTANTS_H
#include <vector>
#include <limits>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <queue>

#define mapSizeX 20
#define mapSizeY 20
#define gridSize 45.f
#define windowSize 900

struct Coordinate{
    int row,col;
    int wage = std::numeric_limits<int>::max();
}typedef Coordinate;

extern Coordinate startPoint;
extern Coordinate finishPoint;
extern Coordinate newTileCoordinate;
extern std::vector<Coordinate> wallArr;
extern sf::RectangleShape tileMap[mapSizeX][mapSizeY];
extern std::vector<std::vector<Coordinate>> shortestPathVect;

#endif //PROJECT_CPP_CONSTANTS_H
