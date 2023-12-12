//
// Created by USER on 12.12.2023.
//

#ifndef PROJECT_CPP_BFS_H
#define PROJECT_CPP_BFS_H

#include "../constants.h"
#include "../grid/Grid.h"

class BFS {
    friend class Grid;
private:
    static void returnNeighboor(Coordinate &coord, std::queue<Coordinate> &queue, std::vector<Coordinate> &visited);
    std::queue<Coordinate> q;
    std::vector<Coordinate> visitedNodes;
    std::vector<Coordinate> BFS_alg();


};


#endif //PROJECT_CPP_BFS_H
