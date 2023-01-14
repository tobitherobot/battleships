#include "Field.h"

#include <iostream>

Field::Field() {
    shipComponents = 17;
    third = false;
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
    bool incomplete = true;
    while(incomplete) {
        std::string coordinates;
        int first;
        int second;
        std::cout << "Enter coordinates to shoot at. Example: A7" << std::endl;
        std::cin >> coordinates;
        first = charToInt(coordinates.at(0));
        second = int(coordinates.at(1) - 48);
        std::cout << first << second << std::endl;

        if (enemy.checkPos(first, second) == 'O') {
            std::cout << "Hit!" << std::endl;
            enemy.setPos(first, second, 'X');
            removeHitComponent(enemy ,first, second);
            enemy.reduceShipComponents();
            incomplete = false;
        } else {
            std::cout << "Miss!" << std::endl;
            enemy.setPos(first, second, 'M');
            incomplete = false;
        }
    }
    
};

void Field::removeHitComponent(Field &enemy, int first, int second) {
    bool ship5destroyed = true;
    bool ship4destroyed = true;
    bool ship3destroyed = true;
    bool ship32destroyed = true;
    bool ship2destroyed = true;

    for (int i = 0; i < 5; i++) {
        if (first == enemy.ship5[i][0] && second == enemy.ship5[i][1]) {
            enemy.ship5[i][0] = 66;
            enemy.ship5[i][1] = 66;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (first == enemy.ship4[i][0] && second == enemy.ship4[i][1]) {
            enemy.ship4[i][0] = 66;
            enemy.ship4[i][1] = 66;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (first == enemy.ship3[i][0] && second == enemy.ship3[i][1]) {
            enemy.ship3[i][0] = 66;
            enemy.ship3[i][1] = 66;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (first == enemy.ship32[i][0] && second == enemy.ship32[i][1]) {
            enemy.ship32[i][0] = 66;
            enemy.ship32[i][1] = 66;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (first == enemy.ship2[i][0] && second == enemy.ship2[i][1]) {
            enemy.ship2[i][0] = 66;
            enemy.ship2[i][1] = 66;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            if (enemy.ship5[i][j] != 66) {
                ship5destroyed = false;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            if (enemy.ship5[i][j] != 66) {
                ship4destroyed = false;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (enemy.ship5[i][j] != 66) {
                ship3destroyed = false;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (enemy.ship5[i][j] != 66) {
                ship32destroyed = false;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (enemy.ship5[i][j] != 66) {
                ship2destroyed = false;
            }
        }
    }
    if (ship5destroyed) {
        std::cout << "You destroyed a ship with length 5!" << std::endl;
        enemy.ship5[0][0] = 99;
    }
    if (ship4destroyed) {
        std::cout << "You destroyed a ship with length 4!" << std::endl;
        enemy.ship4[0][0] = 99;
    }
    if (ship3destroyed) {
        std::cout << "You destroyed a ship with length 3!" << std::endl;
        enemy.ship3[0][0] = 99;
    }
    if (ship32destroyed) {
        std::cout << "You destroyed a ship with length 3!" << std::endl;
        enemy.ship32[0][0] = 99;
    }
    if (ship2destroyed) {
        std::cout << "You destroyed a ship with length 2!" << std::endl;
        enemy.ship2[0][0] = 99;
    }
}

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

        std::cout << firstPosY << firstPosX << secondPosY << secondPosX << std::endl;

        if (firstPosY < 0 || firstPosY > 9 || firstPosX < 0 || firstPosX > 9 || secondPosY < 0 || secondPosY > 9 || secondPosX < 0 || secondPosX > 9) {
            std::cout << "Your input " << input << " is incorrect! Please try again!" << std::endl;
            continue;
        } else if (firstPosY != secondPosY && firstPosX != secondPosX) {
            std::cout << "Your coordinates " << input << " are not in one row/column! Please try again!" << std::endl;
            continue;
        } else if (firstPosY - secondPosY != 0 && abs(firstPosX - secondPosX) + 1 != len || firstPosY - secondPosY == 0 && abs(firstPosX - secondPosX) + 1 != len) {
            std::cout << "Your input " << input << " is not length " << len << "! Please try again!" << std::endl;
            continue;
        }

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
                switch(len) {
                    case 5:
                        ship5[i][0] = firstPosY - 1 + i;
                        ship5[i][1] = firstPosX - 1;
                        break;
                    case 4:
                        ship4[i][0] = firstPosY - 1 + i;
                        ship4[i][1] = firstPosX - 1;
                        break;
                    case 3:
                        if (!third) {
                            ship3[i][0] = firstPosY - 1 + i;
                            ship3[i][1] = firstPosX - 1;
                        } else {
                            ship32[i][0] = firstPosY - 1 + i;
                            ship32[i][1] = firstPosX - 1;
                        }
                        break;
                    case 2:
                        ship2[i][0] = firstPosY - 1 + i;
                        ship2[i][1] = firstPosX - 1;
                    break;
                }
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
                switch(len) {
                    case 5:
                        ship5[i][0] = firstPosY - 1;
                        ship5[i][1] = firstPosX - 1 + i;
                        break;
                    case 4:
                        ship4[i][0] = firstPosY - 1;
                        ship4[i][1] = firstPosX - 1 + i;
                        break;
                    case 3:
                        if (!third) {
                            ship3[i][0] = firstPosY - 1;
                            ship3[i][1] = firstPosX - 1 + i;
                        } else {
                            ship32[i][0] = firstPosY - 1;
                            ship32[i][1] = firstPosX - 1 + i;
                        }
                        break;
                    case 2:
                        ship2[i][0] = firstPosY - 1;
                        ship2[i][1] = firstPosX - 1 + i;
                    break;
                }
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