//
// Created by USER on 16.10.2023.
//

#ifndef PROJECT_CPP_DJIKSTRA_H
#define PROJECT_CPP_DJIKSTRA_H

#include "../constants.h"

Coordinate startPoint;
Coordinate finishPoint;
Coordinate newTileCoordinate;
std::vector<Coordinate> wallArr;

class Grid;


class Djikstra {
    friend class Grid;
private:
    std::vector<visitedNode> coordsOfVisitedTiles;

};


#endif //PROJECT_CPP_DJIKSTRA_H
/*
 *  Co ma robić ten algorytm :
 *  Algorytm Dijkstry jest używany do znalezienia najkrótszej ścieżki w grafie ważonym od jednego punktu (źródła) do wszystkich pozostałych punktów w grafie.
 *  W naszym przypadku będziemy go używać do znalezienia najkrótszej ścieżki od startPoint do finishPoint w naszej planszy.
 *
 *  1. Inicjalizacja:
 *     - Utwórz zbiór odwiedzonych punktów i zainicjuj go jako pusty.
 *     - Utwórz wektor wagi, który będzie przechowywał odległości od startPoint do wszystkich innych punktów na planszy.
 *     - Inicjalizuj wagi punktów jako "nieskończoność" (dla punktów odległych od startPoint) i 0 dla samego startPoint.
 *      Ten punkt został zrealizowany za pomocąstruktury visitedNode.
 *
 *  2. Iteracyjne odwiedzanie punktów:
 *     - Iteruj, dopóki istnieją nieodwiedzone punkty:
 *       - Wybierz punkt o najmniejszej wadze z wierzchołków nieodwiedzonych.
 *       - Oznacz ten punkt jako odwiedzony.
 *
 *  3. Aktualizacja wag:
 *     - Dla każdego sąsiedniego punktu, który jeszcze nie został odwiedzony i jest osiągalny z aktualnego punktu:
 *       - Oblicz nową wagę dla tego punktu jako suma wagi aktualnego punktu i wagi krawędzi między nimi.
 *       - Jeśli nowa waga jest mniejsza od poprzedniej wagi dla tego punktu, zaktualizuj wagę punktu.
 *
 *  4. Powrót do 2:
 *     - Powtarzaj kroki 2 i 3, aż wszystkie punkty zostaną odwiedzone.
 *
 *  5. Wyznaczenie najkrótszej ścieżki:
 *     - Rozpocznij od finishPoint i przejdź do startPoint, śledząc ścieżkę na podstawie wag punktów.
 *     - Ścieżka będzie odwrócona, więc odwróć ją, aby uzyskać kolejność od startPoint do finishPoint.
 *
 *  6. Zakończenie:
 *     - Wynikiem algorytmu będzie najkrótsza ścieżka od startPoint do finishPoint oraz jej długość.
 */
