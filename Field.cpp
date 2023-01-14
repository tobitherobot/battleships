#include <iostream>
#include "Field.h"

Field::Field() 
{    
    countShipsHit = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            charField[i][j] = '~';
        }
    }
};

// places a ship on the field, coords must be ordered properly so the loop works, no check if coords are correct
Field* Field::placeShip(int firstPosX, int firstPosY, int secondPosX, int secondPosY) 
{
    for (int i = firstPosX; i <= secondPosX; i++) {
        for (int j = firstPosY; j <= secondPosY; j++) {
            charField[i][j] = 'O';
        }
    }
    return this;
}

// shoot on the field, places a X when hit and a M when missed, returns true when a ship is hit
bool Field::shootAt(int posX, int posY) 
{
    if (charField[posX][posY] == 'O') {
        charField[posX][posY] = 'X';
        return true;
    }
    else charField[posX][posY] = 'M';
    return false;
}

// prints the entire char field in a readable format
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

// prints the field, but skips placed/undiscovered ships (for opponent view only)
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

char Field::charAt(int posX, int posY) {
    return charField[posX][posY];
}