//
// Created by USER on 16.10.2023.
//

#include "Djikstra.h"

/*
 * TODO:
 * Algorytm musi jakoś respektować ściany (wallArr)
 * Algorytm musi działać w mniej rozjebany sposób.
 * Przeczyścić kod by sie nie powtarzał
 */

void changeCoords(int &x,int &y, int dx, int dy)
{
    x+=dx;
    y+=dy;
}

std::vector<Coordinate> Djikstra::shortestPath() {

    // Definiujemy wewnętrzny wektor z wartościami 'nieskończoność' - nie wiemy jaki jest dystans na początku do każdego tile'a.
    std::vector<int> innerVector(mapSizeY, std::numeric_limits<int>::max());

    //Definiujemy wektor 2D za pomocą wektora wewntętrznego. Potrzebny jest nam on do kontrolowania kosztu dostania się do każdego z kwadracików
    std::vector<std::vector<int>> distance(mapSizeX, innerVector);

    /*
     * This line declares a priority queue named `pq` that stores pairs of an integer (representing distance) and a `Coordinate` struct.
     * It uses a `std::vector` as the underlying container and custom comparison logic provided by the `CompareDistance`
     * comparator class to prioritize elements based on their distances.
     */
    std::priority_queue<std::pair<int, Coordinate>, std::vector<std::pair<int,Coordinate>>, CompareDistance> pq;

    //wypelnimy danymi -1,-1 ktore potem zmienimy na odpowiednie
    std::vector<Coordinate> uninitializedPath(mapSizeY);
    std::vector<Coordinate> predecessor;


    //printf("Predecessor zainicjowany.\n"); dziala
    startPoint.wage = 0;
    pq.emplace(startPoint.wage,startPoint);

    //pozycje sa jako 0,50,100,150 etc. w tileMap
    //wypelniam kolejke wg najblizszych koordynatow
    while(!pq.empty()){
        auto current = pq.top().second;
        pq.pop();

        //Sprawdzamy sasiadow
        for(int dx = -1;dx<=1;dx++){
            for(int dy = -1;dy<=1;dy++){
                //pomijamy aktualny node
                if(dx ==0 && dy == 0) continue;
                int newRow = current.row;
                int newCol = current.col;
                changeCoords(newRow,newCol,dx,dy);
                printf("ROW: %d COL: %d \n",newRow,newCol);
                if(!wallArr.empty())
                {
                    bool isWall = false;
                    for(auto & i : wallArr) {
                        if (newRow == i.row && newCol == i.col) {
                            isWall = true;
                        }
                    }
                    if (isWall) changeCoords(newRow,newCol,dx,dy);
                }

                //sprawdzamy czy nowe kolumny i rzedy sa w zasiegu mapy
                if (newRow < mapSizeX && newCol < mapSizeY && newCol >= 0 && newRow >= 0) {
                    //zwiekszamy dystanst o 1 poniewaz poczynilismy jeden krok w jakas strone
                    int newDistance = current.wage + 1;

                    if (newDistance < distance[newRow][newCol]) {
                        //distance update
                        distance[newRow][newCol] = newDistance;
                        //update predecessora
                        predecessor.push_back(current);
                        //dodajemy sasiada
                        pq.emplace(newDistance, Coordinate{newRow, newCol, newDistance});
                    }
                }

            }
        }

    }
    printf("Sciezka znaleziona\n");
    printf("malowanie...\n");
    return predecessor;
}

