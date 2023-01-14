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
        countShipsHit += 1;
        return true;
    }
    else charField[posX][posY] = 'M';
    return false;
}

// checks if, after a hit, the given coords correspond to a completely hit/sunk ship
bool Field::isShipSunk(int posX, int posY) {
    if (charAt(posX, posY) == 'X') {
        return (isShipSunkRecursive(posX-1, posY, 0) && isShipSunkRecursive(posX, posY+1, 1) && isShipSunkRecursive(posX+1, posY, 2) && isShipSunkRecursive(posX, posY-1, 3));
    }
    else return false;
}

// recursive function for checking if a ship is completely hit/sunk
bool Field::isShipSunkRecursive(int posX, int posY, int direction) {

    if (posX < 0 || posX > 9 || posY < 0 || posY > 9) return true;
    else if (charAt(posX, posY) == '~' || charAt(posX, posY) == 'M') return true;
    else if (charAt(posX, posY) == 'O') return false;
    else if (charAt(posX, posY) == 'X') {
        if (direction == 0) return isShipSunkRecursive(posX-1, posY, direction);
        else if (direction == 1) return isShipSunkRecursive(posX, posY+1, direction);
        else if (direction == 2) return isShipSunkRecursive(posX+1, posY, direction);
        else return isShipSunkRecursive(posX, posY-1, direction);
    }
    else return true;
}

// checks, if any position surrounding the given coordinates is occupied by a ship already
bool Field::isShipAround(int posX, int posY) {

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

             int x = posX + i;
             int y = posY + j;
             if (x < 0 || x > 9 || y < 0 || y > 9) continue;
             else if (charField[x][y] == 'O') return true;
        }
    }
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