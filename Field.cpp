#include <iostream>
#include "Field.h"

Field::Field() {
    
    countShipsHit = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            charField[i][j] = '~';
        }
    }
};

Field* Field::placeShip(int firstPosX, int firstPosY, int secondPosX, int secondPosY) {

    for (int i = firstPosX; i <= secondPosX; i++) {
        for (int j = firstPosY; j <= secondPosY; j++) {
            charField[i][j] = 'O';
        }
    }
    return this;
}

bool Field::shootAt(int posX, int posY) {

    if (charField[posX][posY] == 'O') {
        charField[posX][posY] = 'X';
        return true;
    }
    else charField[posX][posY] = 'M';
    return false;
}

void Field::printField() {
    
    std::cout << "  1 2 3 4 5 6 7 8 9 10" << std::endl;
    char letter = 'A';

    for (int i = 0; i < 10; i++) 
    {
        std::cout << letter << " ";
        letter = (char) (letter + 1);

        for (int j = 0; j < 10; j++) {
            std::cout << charField[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

void Field::printFog() {
    
    std::cout << "  1 2 3 4 5 6 7 8 9 10" << std::endl;
    char letter = 'A';

    for (int i = 0; i < 10; i++) 
    {
        std::cout << letter << " ";
        letter = (char) (letter + 1);

        for (int j = 0; j < 10; j++) {
            if (charField[i][j] == 'O') std::cout << "~ ";
            else std::cout << charField[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};