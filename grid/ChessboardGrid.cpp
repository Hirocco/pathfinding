#include "ChessboardGrid.h"

ChessboardGrid::ChessboardGrid() /* : size(size), squareSize(squareSize)*/ { //okomentowane, to jest to samo co this->size = size; etc
    window.create(sf::VideoMode(windowSize, windowSize),"Grid"); //okno zawsze bedzie kwadratem mieszczacym wszystkie pola
}

void ChessboardGrid::createGrid() {
    sf::RectangleShape shape(sf::Vector2f(gridSize,gridSize)); // gridSize jest 50.f
    shape.setFillColor(sf::Color::White); // Set the circle color
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.f);
    //generowanie mapy
    for(int x = 0;x < mapSizeX;x ++){
        for(int y = 0;y< mapSizeY; y++){
            shape.setPosition(float(y)*gridSize,float(x)*gridSize);
            tileMap[x][y] = shape;
        }
    }
}

void ChessboardGrid::handleMouseEvents(sf::Event eventHandler) { //teraz to nie działa XDXDXDXDXD
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
                if (tileMap[row][col].getFillColor() == sf::Color::Black){
                    // Jeśli tile jest czarny i został kliknięty, zmień na biały
                    tileMap[row][col].setFillColor(sf::Color::White);
                    tileMap[row][col].setOutlineColor(sf::Color::Black);

                    newTileCoordinate.row = row;
                    newTileCoordinate.col = col;
                    wallArr.push_back(newTileCoordinate); //zapisujemy pozycje kawałka naszej sciany
                    printf("dodano row/col: %d %d" , newTileCoordinate.row , newTileCoordinate.col);

                } else {
                    // Jeśli tile jest biały i został kliknięty, zmień na czarny
                    tileMap[row][col].setFillColor(sf::Color::Black);
                    tileMap[row][col].setOutlineColor(sf::Color::Green);
                    newTileCoordinate.row = row;
                    newTileCoordinate.col = col;

                    for(auto iterator = wallArr.begin(); iterator < wallArr.end() ; ++iterator){
                        if(iterator->col == newTileCoordinate.col && iterator->row == newTileCoordinate.row) {
                            wallArr.erase(iterator); //znaleziony koordynat jest usuwany
                            printf("usunieto row/col: %d %d " , newTileCoordinate.row , newTileCoordinate.col);
                            break;
                        }
                    }

                }
            }
        }
    }
}

void ChessboardGrid::drawGrid() {
    for(int x = 0;x < mapSizeX; x++) {
        for (int y = 0; y < mapSizeY; y++) {
            window.draw(tileMap[x][y]);
        }
    }
}

void ChessboardGrid::run() {
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
        window.display(); // Display the window
    }
}
