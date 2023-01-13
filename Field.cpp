#include "Field.h"

#include <iostream>

Field::Field() {
    shipComponents = 17;
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

void Field::printFogField() {
    //prints the field without showing ships
    char letter = 'A';

    std::cout << "  1 2 3 4 5 6 7 8 9 10" << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << letter << " ";
        letter = (char) (letter + 1);
        for (int j = 0; j < 10; j++) {
            if (field[i][j] == 'O') {
                std::cout << "~ ";
            } else {
                std::cout << field[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

void Field::shoot(Field &enemy) {
    std::string coordinates;
    int first;
    int second;

    std::cout << "Enter coordinates to shoot at. Example: A7" << std::endl;
    std::cin >> coordinates;
    first = charToInt(coordinates.at(0));
    second = int(coordinates.at(1) - 48);

    if (enemy.checkPos(first,second) == 'O') {
        std::cout << "Hit!" << std::endl;
        enemy.setPos(first, second, 'X');
        enemy.reduceShipComponents();
    } else {
        std::cout << "Miss!" << std::endl;
        enemy.setPos(first, second, 'M');
    }
};

void Field::setPos(int first, int second, char symbol) {
    field[first - 1][second - 1] = symbol;
};

void Field::reduceShipComponents() {
    shipComponents--;
};

int Field::getShipComponents() {
    return shipComponents;
}

int Field::charToInt(char ch){
    return int(ch - 64);
};

char Field::checkPos(int first, int second) {
    //returns the state of the given location
    return field[first - 1][second - 1];
};

void Field::placeShip(int len) {
    //places a ship of the length len
    bool incomplete = true;
    bigLoop:
    while (incomplete) {
        std::string input;
        int firstPosX;
        int firstPosY;
        int secondPosX;
        int secondPosY;

        std::cout << "Please enter the coordinates you want to place your ship at (length " << len << ") Example: B3-B5, C3-D3" << std::endl;
        std::cin >> input;

        firstPosY = charToInt(input.at(0));
        firstPosX = int(input.at(1) - 48);
        secondPosY = charToInt(input.at(3));
        secondPosX = int(input.at(4) - 48);

        std::cout << firstPosX << firstPosY << secondPosX << secondPosY << std::endl;

        if (firstPosY - secondPosY != 0) {
            //Fall, dass das Schiff in X-Richtung platziert wurde
            for (int i = 0; i < len; i++) {
                if (!checkSurroundings(firstPosY + i, firstPosX)) {
                    std::cout << "Invalid location, try again." << std::endl;
                    goto bigLoop;
                }
            }
            for (int i = 0; i < len; i++) {
                field[firstPosY - 1 + i][firstPosX - 1] = 'O';
            }
        } else {
            //Fall, dass das Schiff in Y-Richtung platziert wurde
            for (int i = 0; i < len; i++) {
                if (!checkSurroundings(firstPosY, firstPosX + i)) {
                    std::cout << "Invalid location, try again." << std::endl;
                    goto bigLoop;
                }
            }
            for (int i = 0; i < len; i++) {
                field[firstPosY - 1][firstPosX - 1 + i] = 'O';
            }
        }
        incomplete = false;
    }
};

bool Field::checkSurroundings(int y, int x) {
    //checks if the chosen or the surrounding locations contain ships
    y--;
    x--;

    //top-left
    if (y == 1 && x == 1) {
        for (int f = 0; f < 2; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[y + f][x + s] == 'O') return false;
            }
        }
        return true;
    }
    //bottom-left
    if (y == 10 && x == 1) {
        for (int f = -1; f < 1; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[y + f][x + s] == 'O') return false;
            }
        }
        return true;
    }
    //bottom-right
    if (y == 10 && x == 10) {
        for (int f = -1; f < 1; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[y + f][x + s] == 'O') return false;
            }
        }
        return true;
    }
    //top-right
    if (y == 1 && x == 10) {
        for (int f = 0; f < 2; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[y + f][x + s] == 'O') return false;
            }
        }
        return true;
    }
    //left
    if (x == 1) {
        for (int f = -1; f < 2; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[y + f][x + s] == 'O') return false;
            }
        }
        return true;
    }
    //bottom
    if (y == 10) {
        for (int f = -1; f < 1; f++) {
            for (int s = -1; s < 2; s++) {
                if (field[y + f][x + s] == 'O') return false;
            }
        }
        return true;
    }
    //right
    if (x == 10) {
        for (int f = -1; f < 2; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[y + f][x + s] == 'O') return false;
            }
        }
        return true;
    }
    //top
    if (y == 1) {
        for (int f = 0; f < 2; f++) {
            for (int s = -1; s < 2; s++) {
                if (field[y + f][x + s] == 'O') return false;
            }
        }
        return true;
    }
    //no walls
    for (int f = -1; f < 2; f++) {
        for (int s = -1; s < 2; s++) {
            if (field[y + f][x + s] == 'O') return false;
        }
    }
    return true;
};