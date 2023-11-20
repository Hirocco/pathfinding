//
// Created by USER on 16.10.2023.
//

#ifndef PROJECT_CPP_DJIKSTRA_H
#define PROJECT_CPP_DJIKSTRA_H

#include "../constants.h"
#include "../grid/Grid.h"

class Grid;

class Djikstra {
    friend class Grid;
private:
    std::vector<std::vector<Coordinate>> shortestPath();
    /*
    komparator do priorytezowania mniejszych dystansów.
    jest to funktor (obiekt który można wywołać jak funkcje) - wiecej w notatki.txt
    overload ()
    */
    struct CompareDistance{
        bool operator()(const std::pair<int, Coordinate>& a, const std::pair<int,Coordinate>& b){
            return a.first> b.first;
        }
    }typedef CompareDistance;

};

#endif //PROJECT_CPP_DJIKSTRA_H


