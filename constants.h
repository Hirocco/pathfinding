//
// Created by USER on 19.10.2023.
//

#ifndef PROJECT_CPP_CONSTANTS_H
#define PROJECT_CPP_CONSTANTS_H
#include <vector>
#include <limits>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#define mapSizeX 20
#define mapSizeY 20
#define gridSize 50.f
#define windowSize 900

struct Coordinate{
    int row,col;
}typedef Coordinate;

struct visitedNode{
    Coordinate nodeCoordinate;
    int wage = std::numeric_limits<int>::max(); // Zainicjuj jako nieskończoność, bo nienzamy najkrotszej drogi
}typedef visitedNode;

extern Coordinate startPoint;
extern Coordinate finishPoint;
extern Coordinate newTileCoordinate;
extern std::vector<Coordinate> wallArr;

#endif //PROJECT_CPP_CONSTANTS_H
