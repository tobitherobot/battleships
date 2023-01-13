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

char Field::checkPos(int first, int second) {
    //returns the state of the given location
    return field[first - 1][second - 1];
};
void Field::shoot(Field enemy) {
    std::string coordinates;
    int first;
    int second;

    std::cout << "Enter coordinates to shoot at. Example: A7" << std::endl;
    std::cin >> coordinates;
    first = charToInt(coordinates.at(0));
    second = int(coordinates.at(1) - 48);

    if(enemy.checkPos(first,second) == 'O') {
        std::cout << "Hit!" << std::endl;
        enemy.setpos(first, second, 'X');
        enemy.reduceShipComponents();
    } else {
        std::cout << "Miss!" << std::endl;
        enemy.setpos(first, second, 'M');
    }
};

void Field::reduceShipComponents() {
    shipComponents--;
};

int Field::charToInt(char ch){
    return int(ch - 64);
};

char Field::checkPos(int first, int second) {
    //returns the state of the given location
    return field[first - 1][second - 1];
};

void Field::setpos(int first, int second, char symbol) {
    field[first-1][second-1] = symbol;
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
        int lowerNumber;
        int lowerLetter;

        std::cout << "Please enter the coordinates you want to place your ship at (length " << len << ") Example: B3-B5, C3-D3" << std::endl;
        std::cin >> input;

        firstPosX = charToInt(input.at(0));
        firstPosY = int(input.at(1) - 48);
        secondPosX = charToInt(input.at(3));
        secondPosY = int(input.at(4) - 48);

        lowerNumber = std::min(firstPosY, secondPosY);
        lowerLetter = std::min(firstPosX, secondPosX);

        if (firstPosY - secondPosY != 0) {
            //Fall, dass das Schiff in X-Richtung platziert wurde
            for (int i = 0; i < len; i++) {
                if (!checkSurroundings(firstPosX + i, firstPosY)) {
                    std::cout << "Invalid location, try again." << std::endl;
                    goto bigLoop;
                }
            }
            for (int i = 0; i < len; i++) {
                field[firstPosY - 1][firstPosX + i - 1] = 'O';
            }
        } else {
            //Fall, dass das Schiff in Y-Richtung platziert wurde
            for (int i = 0; i < len; i++) {
                if (!checkSurroundings(firstPosX, firstPosY + i)) {
                    std::cout << "Invalid location, try again." << std::endl;
                    goto bigLoop;
                }
            }
            for (int i = 0; i < len; i++) {
                field[firstPosY + i - 1][firstPosX - 1] = 'O';
            }
        }
        incomplete = false;
    }
};

bool Field::checkSurroundings(int first, int second) {
    //checks if the chosen or the surrounding locations contain ships

    //top-left
    if (first == 1 && second == 1) {
        for (int f = 0; f < 2; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[first + f - 1][second + s - 1] == 'O') return false;
            }
        }
        return true;
    }
    //top-right
    if (first == 10 && second == 1) {
        for (int f = -1; f < 1; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[first + f - 1][second + s - 1] == 'O') return false;
            }
        }
        return true;
    }
    //bottom-right
    if (first == 10 && second == 10) {
        for (int f = -1; f < 1; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[first + f - 1][second + s - 1] == 'O') return false;
            }
        }
        return true;
    }
    //bottom-left
    if (first == 1 && second == 10) {
        for (int f = 0; f < 2; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[first + f - 1][second + s - 1] == 'O') return false;
            }
        }
        return true;
    }
    //top
    if (second == 1) {
        for (int f = -1; f < 2; f++) {
            for (int s = 0; s < 2; s++) {
                if (field[first + f - 1][second + s - 1] == 'O') return false;
            }
        }
        return true;
    }
    //right
    if (first == 10) {
        for (int f = -1; f < 1; f++) {
            for (int s = -1; s < 2; s++) {
                if (field[first + f - 1][second + s - 1] == 'O') return false;
            }
        }
        return true;
    }
    //bottom
    if (second == 10) {
        for (int f = -1; f < 2; f++) {
            for (int s = -1; s < 1; s++) {
                if (field[first + f - 1][second + s - 1] == 'O') return false;
            }
        }
        return true;
    }
    //left
    if (first == 1) {
        for (int f = 0; f < 2; f++) {
            for (int s = -1; s < 2; s++) {
                if (field[first + f - 1][second + s - 1] == 'O') return false;
            }
        }
        return true;
    }
    //no walls
    for (int f = -1; f < 2; f++) {
        for (int s = -1; s < 2; s++) {
            if (field[first + f - 1][second + s - 1] == 'O') return false;
        }
    }
    return true;
};