#include "BFS.h"

void BFS::returnNeighboor(Coordinate &coord, std::queue<Coordinate> &queue, std::vector<Coordinate> &visited)
{
    for(int dx=-1; dx<=1; dx++){
        for(int dy=-1; dy<=1; dy++){
            if(dx==0 && dy == 0 || dx == dy || dx == -dy) continue;
            Coordinate neighboor;
            if(!std::count(wallArr.begin(),wallArr.end(), Coordinate{coord.row + dx,coord.col + dy}) &&
                !std::count(visited.begin(),visited.end(),Coordinate{coord.row + dx,coord.col + dy})){
                if(coord.row + dx < mapSizeY && coord.col + dy < mapSizeX) {
                    neighboor.row = coord.row + dx;
                    neighboor.col = coord.col + dy;
                    neighboor.wage = coord.wage + 1;
                    queue.push(neighboor);

                } else continue;
            }
            else continue;
        }
    }
}

std::vector<Coordinate> BFS::BFS_alg() {
    Coordinate curr = startPoint;
    q.push(curr);
    visitedNodes.push_back(curr);
    while (!q.empty())
    {
        q.pop();
        //do kolejki dodajemy 4 kolejnych sasiadow
        returnNeighboor(curr, q,visitedNodes);
        //nastepny w kolejce jest kolejnym
        curr = q.front();
        visitedNodes.push_back(curr);
        if(curr.row == finishPoint.row && curr.col == finishPoint.col) {
            printf("Znaleziono sciezke!\n");
            printf("malowanie...\n");

            return visitedNodes;
        }
    }
    printf("Brak ścieżki!\n");
    return {};
}
