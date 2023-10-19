#include "grid/ChessboardGrid.h"

Coordinate startPoint;
Coordinate finishPoint;
Coordinate newTileCoordinate;
std::vector<Coordinate> wallArr;

int main() {

    ChessboardGrid grid;
    grid.run();

    return 0;
}