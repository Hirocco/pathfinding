#include "Grid.h"
#include "../algorithm/Djikstra.h"
#include "../algorithm/BFS.h"


Grid::Grid() /* : size(size), squareSize(squareSize)*/ { //okomentowane, to jest to samo co this->size = size; etc
    window.create(sf::VideoMode(windowSize, windowSize),"Grid"); //okno zawsze bedzie kwadratem mieszczacym wszystkie pola
}

void Grid::createGrid() {
    sf::RectangleShape shape(sf::Vector2f(gridSize,gridSize)); // gridSize jest 50.f
    shape.setFillColor(sf::Color::White); // Set the circle color
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.f);
    //generowanie mapy
    for(int x = 0;x < mapSizeX;x ++){
        for(int y = 0;y< mapSizeY; y++){
            shape.setPosition(float(y)*gridSize,float(x)*gridSize);
            tileMap[x][y] = shape;
            //printf("Position X : %f Position Y: %f\n", shape.getPosition().x, shape.getPosition().y);
        }
    }
}

void Grid::handleMouseEvents(sf::Event eventHandler) {
    Djikstra alg;
    BFS bfs_alg;
    //zbieramy i mapujemy pozycje
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mousePositionView = window.mapPixelToCoords(mousePosition);

    int row = static_cast<int>(mousePositionView.y/gridSize); //static_cast<int> konwertuje podwójną prezcyje na int
    int col = static_cast<int>(mousePositionView.x/gridSize);

    //sprawdzamy pozycje myszki
    if (row >= 0 && row < windowSize && col >= 0 && col < windowSize) {
        if ( eventHandler.type == sf::Event::MouseButtonPressed && eventHandler.mouseButton.button == sf::Mouse::Left) {

            sf::Vector2f tilePosition = sf::Vector2f (float(col)*gridSize,float(row)*gridSize);

            //Jak jestesmy na pozycji i klikniemy to zmien kolor
            if (sf::FloatRect(tilePosition.x, tilePosition.y, gridSize, gridSize).contains(mousePositionView)) {
                if (tileMap[row][col].getFillColor() == sf::Color::White){
                    // Jeśli tile jest czarny i został kliknięty, zmień na biały
                    tileMap[row][col].setFillColor(sf::Color::Black);
                    tileMap[row][col].setOutlineColor(sf::Color::White);

                    newTileCoordinate.row = row;
                    newTileCoordinate.col = col;
                    wallArr.push_back(newTileCoordinate); //zapisujemy pozycje kawałka naszej sciany
                    printf("\ndodano row/col: %d %d\n" , newTileCoordinate.row , newTileCoordinate.col);

                } else {
                    // Jeśli tile jest biały i został kliknięty, zmień na czarny
                    tileMap[row][col].setFillColor(sf::Color::White);
                    tileMap[row][col].setOutlineColor(sf::Color::Black);
                    newTileCoordinate.row = row;
                    newTileCoordinate.col = col;

                    for(auto iterator = wallArr.begin(); iterator < wallArr.end() ; ++iterator){
                        if(iterator->col == newTileCoordinate.col && iterator->row == newTileCoordinate.row) {
                            wallArr.erase(iterator); //znaleziony koordynat jest usuwany
                            printf("\nusunieto row/col: %d %d \n" , newTileCoordinate.row , newTileCoordinate.col);
                            break;
                        }
                    }
                }
            }
        }
        if(eventHandler.type == sf::Event::KeyPressed && eventHandler.key.code == sf::Keyboard::D){
            printf("Rozpoczynam algorytm Djisktry. \n");
            shortestPathVect = alg.shortestPath();
            shortestPathVect = bfs_alg.BFS_alg();
        }
        if(eventHandler.type == sf::Event::KeyPressed && eventHandler.key.code == sf::Keyboard::B){
            printf("Rozpoczynam algorytm BFS. \n");
            shortestPathVect = bfs_alg.BFS_alg();
        }

        if(eventHandler.type == sf::Event::KeyPressed){
            sf::Vector2f tilePosition = sf::Vector2f (float(col)*gridSize,float(row)*gridSize);
            if (sf::FloatRect(tilePosition.x, tilePosition.y, gridSize, gridSize).contains(mousePositionView)) {
                //Zapisywanie i ustawianie wspolrzednych startowych
                if(tileMap[row][col].getFillColor() == sf::Color::White && eventHandler.key.code == sf::Keyboard::S ){
                    startPoint.row = row;
                    startPoint.col = col;
                    tileMap[row][col].setFillColor(sf::Color::Yellow);
                    tileMap[row][col].setOutlineColor(sf::Color::Blue);
                    printf("\nDodano punkt startowy ze wspolrzednymi: %d %d\n", row,col);
                }
                else if(tileMap[row][col].getFillColor() == sf::Color::Yellow && eventHandler.key.code == sf::Keyboard::S){
                    startPoint.row = -1;
                    startPoint.col = -1;
                    tileMap[row][col].setFillColor(sf::Color::White);
                    tileMap[row][col].setOutlineColor(sf::Color::Black);
                    printf("\nUsunięto punkt (aktualne wsporlzedne to -1,-1) startowy ze wspolrzednymi: %d %d\n", row,col);
                }
                //zapisywanie i ustawianie wspolrzednych koncowych
                if(tileMap[row][col].getFillColor() == sf::Color::White && eventHandler.key.code == sf::Keyboard::F){
                    finishPoint.row = row;
                    finishPoint.col = col;
                    tileMap[row][col].setFillColor(sf::Color::Blue);
                    tileMap[row][col].setOutlineColor(sf::Color::Yellow);
                    printf("\nDodano punkt koncowy ze wspolrzednymi %d %d\n", row,col);
                }else if(tileMap[row][col].getFillColor() == sf::Color::Blue && eventHandler.key.code == sf::Keyboard::F){
                    finishPoint.row = -1;
                    finishPoint.col = -1;
                    tileMap[row][col].setFillColor(sf::Color::White);
                    tileMap[row][col].setOutlineColor(sf::Color::Black);
                    printf("\nUsunięto punkt (aktualne wsporlzedne to -1,-1) koncowy ze wspolrzednymi: %d %d\n", row,col);                }

            }
        }
    }
}

void Grid::drawGrid() {
    for(int x = 0;x < mapSizeX; x++) {
        for (int y = 0; y < mapSizeY; y++) {
            window.draw(tileMap[x][y]);
        }
    }
}
void Grid::drawPath() {
    sf::RectangleShape shape(sf::Vector2f(gridSize,gridSize)); // gridSize jest 50.f
    shape.setFillColor(sf::Color::Green); // Set the circle color
    shape.setOutlineThickness(2.f);
    if(!shortestPathVect.empty()) {
        for (auto & x : shortestPathVect) {
                shape.setPosition(float(x.col) * gridSize,
                                  float(x.row) * gridSize);
                window.draw(shape);
        }

        shape.setFillColor(sf::Color::Yellow);
        shape.setPosition(float(shortestPathVect[0].col)*gridSize,
                          float(shortestPathVect[0].row)*gridSize);
        window.draw(shape);
        shape.setFillColor(sf::Color::Blue);
        shape.setPosition(float(shortestPathVect[shortestPathVect.size()-1].col)*gridSize,
                          float(shortestPathVect[shortestPathVect.size()-1].row)*gridSize);
        window.draw(shape);

    }
}

void Grid::run() {
    createGrid();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
            handleMouseEvents(event);
        }
        window.clear(sf::Color::Black);
        drawGrid();
        drawPath();
        window.display(); // Display the window
    }
}




