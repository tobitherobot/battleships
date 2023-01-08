#include "Field.h"

#include <iostream>

Field::Field() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            field[i][j] = '~';
        }
    }
};

void Field::printField() {
    //prints the field
    char letter = 'A';

    std::cout << "  1 2 3 4 5 6 7 8 9 10" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << letter << " ";
        letter = (char) (letter + 1);
        for (int j = 0; j < 10; j++) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

char Field::checkPos(int first, int second) {
    //returns the state of the given location
    return field[first][second];
};

void Field::placeShip(int len) {
    //places a ship of the length len
    
}

bool Field::checkSurroundings(int first, int second) {
    //checks if the chosen or the surrounding locations contain ships

    //top-left
    if (first == 1 && second == 1) {
        for (int f = 0; f < 2; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[first + f][second + s] == 'O') return false;
            }
        }
        return true;
    }
    //top-right
    if (first == 10 && second == 1) {
        for (int f = -1; f < 1; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[first + f][second + s] == 'O') return false;
            }
        }
        return true;
    }
    //bottom-right
    if (first == 10 && second == 10) {
        for (int f = -1; f < 1; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[first + f][second + s] == 'O') return false;
            }
        }
        return true;
    }
    //bottom-left
    if (first == 1 && second == 10) {
        for (int f = 0; f < 2; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[first + f][second + s] == 'O') return false;
            }
        }
        return true;
    }
    //top
    if (second == 1) {
        for (int f = -1; f < 2; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[first + f][second + s] == 'O') return false;
            }
        }
        return true;
    }
    //right
    if (first == 10) {
        for (int f = -1; f < 1; f++) {
            for (int s = -1; s < 2; s++) {
                if (field[first + f][second + s] == 'O') return false;
            }
        }
        return true;
    }
    //bottom
    if (second == 10) {
        for (int f = -1; f < 2; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[first + f][second + s] == 'O') return false;
            }
        }
        return true;
    }
    //left
    if (first == 1) {
        for (int f = 0; f < 2; f++) {
            for (int s = -1; s < 2; s++) {
                if (field[first + f][second + s] == 'O') return false;
            }
        }
        return true;
    }
    //no walls
    for (int f = -1; f < 2; f++) {
        for (int s = -1; s < 2; s++) {
            if (field[first + f][second + s] == 'O') return false;
        }
    }
    return true;
};