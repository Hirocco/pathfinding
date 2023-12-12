#include "grid/Grid.h"

Coordinate startPoint;
Coordinate finishPoint;
Coordinate newTileCoordinate;
std::vector<Coordinate> wallArr;
sf::RectangleShape tileMap[mapSizeX][mapSizeY];
std::vector<Coordinate> shortestPathVect;

int main() {
    Grid grid;
    grid.run();
    return 0;
}

/*
 * Zrób kontrole ze mozna ustawic tylko jeden start i finish point
 * zaczynaj implementowac algorytm djikstry
 */
