#include <iostream>

#include "Field.h"

Field::Field() {
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            field[i][j] = '~';
        }
    }
};

bool Field::shootPos(int posX, int posY) {

    if (field[posX][posY] == 'S') return true;
    else return false;
}

void Field::printField() {
    
    std::cout << "  1 2 3 4 5 6 7 8 9 10" << std::endl;
    char letter = 'A';

    for (int i = 0; i < 10; i++) 
    {
        std::cout << letter << " ";
        letter = (char) (letter + 1);

        for (int j = 0; j < 10; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};