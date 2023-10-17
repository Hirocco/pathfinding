//
// Created by USER on 16.10.2023.
//

#include "ChessboardGrid.h"
/**
 * @param mapSize - wielkosc naszej mapy
 * @param tileSize - wielkosc pojedynczego pola
 * ChessboardGrid - konstructor
 *
 */

ChessboardGrid::ChessboardGrid(int mapSize) /* : size(size), squareSize(squareSize)*/ { //okomentowane, to jest to samo co this->size = size; etc
    this->mapSize = mapSize;
    window.create(sf::VideoMode(mapSize, mapSize),"Grid"); //okno zawsze bedzie kwadratem mieszczacym wszystkie pola
}

void ChessboardGrid::createGrid() {
    //vectory potrzebne do zapamietania pozycji vectorów
    tileMap.resize(mapSize,std::vector<sf::RectangleShape>(mapSize));
    tileRow.resize(mapSize,sf::RectangleShape());

    sf::RectangleShape shape(sf::Vector2f(gridSize,gridSize)); // gridSize jest 50.f
    shape.setFillColor(sf::Color::White); // Set the circle color
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.f);
    //generowanie mapy
    for(float x = 0.f;x<float(mapSize);x+=gridSize){
        tileRow.clear();
        for(float y = 0.f;y<float(mapSize);y+=gridSize){
            shape.setPosition(x, y); // Position the circle in the window
            tileRow.push_back(shape);
        }
        tileMap.push_back(tileRow);
    }
    //JEBAC WEKTORY ZROBN ORMALNA DWUWYMIAROWA I ZOBACZYMY CO BEDZIE

}

void ChessboardGrid::handleMouseEvents() { //teraz to nie działa XDXDXDXDXD
    //zbieramy i mapujemy pozycje
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mousePositionView = window.mapPixelToCoords(mousePosition);

    int row = static_cast<int>(mousePositionView.y/gridSize); //static_cast<int> konwertuje podwójną prezcyje na int
    int col = static_cast<int>(mousePositionView.x/gridSize);

    //sprawdzamy pozycje myszki
    if (row >= 0 && row < mapSize && col >= 0 && col < mapSize) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            printf("row: %d\n",row);
            printf("col: %d\n",col);
            sf::Vector2f tilePosition = sf::Vector2f (col*gridSize,row*gridSize);

            //Jak jestesmy na pozycji i klikniemy to zmien kolor
            if (sf::FloatRect(tilePosition.x,tilePosition.y ,gridSize,gridSize).contains(mousePositionView)) {
                tileMap[row][col].setFillColor(sf::Color::Black);
                tileMap[row][col].setOutlineColor(sf::Color::White);
                printf("Button pressed tile!\n");
            }else {
                // Jak nie to wraca biały
                tileMap[row][col].setFillColor(sf::Color::White);
                tileMap[row][col].setOutlineColor(sf::Color::Black);
            }
        }
    }
}

void ChessboardGrid::drawGrid() {
    for(int x = 0;x<(mapSize);x++) {
        for (int y = 0; y < (mapSize); y++) {
            window.draw(tileMap[x][y]);
        }
    }
}

void ChessboardGrid::run() {
    createGrid();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        handleMouseEvents();
        drawGrid();
        window.display(); // Display the window
    }
}



