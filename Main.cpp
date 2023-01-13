#include "Field.cpp"

#include <stdlib.h>
#include <iostream>

void printTwoFields(Field p1, Field p2) {
    p2.printFogField();
    std::cout << "---------------------" << std::endl;
    p1.printField();
}

void clearConsole() {
    for (int i = 0; i < 50; i++) {
        std::cout << "" << std::endl;
    }
}

int main() {
    Field fieldOne;
    Field fieldTwo;

    int winner = 0;

    std::cout << "Player 1, place your ships!" << std::endl;
    fieldOne.printField();
    fieldOne.placeShip(5);
    fieldOne.printField();
    fieldOne.placeShip(4);
    fieldOne.printField();
    fieldOne.placeShip(3);
    fieldOne.printField();
    fieldOne.placeShip(3);
    fieldOne.printField();
    fieldOne.placeShip(2);
    fieldOne.printField();

    clearConsole();
    
    std::cout << "Player 2, place your ships!" << std::endl;
    fieldTwo.printField();
    fieldTwo.placeShip(5);
    fieldTwo.printField();
    fieldTwo.placeShip(4);
    fieldTwo.printField();
    fieldTwo.placeShip(3);
    fieldTwo.printField();
    fieldTwo.placeShip(3);
    fieldTwo.printField();
    fieldTwo.placeShip(2);
    fieldTwo.printField();

    clearConsole();

    while (winner == 0) {
        //turn player one
        std::cout << "Player 1, it's your turn:" << std::endl;
        printTwoFields(fieldOne, fieldTwo);
        fieldOne.shoot(fieldTwo);
        clearConsole();
        if (fieldTwo.getShipComponents() == 0) {
            winner = 1;
            break;
        }
        //turn player two
        std::cout << "Player 2, it's your turn:" << std::endl;
        printTwoFields(fieldTwo, fieldOne);
        fieldOne.shoot(fieldOne);
        clearConsole();
        if (fieldOne.getShipComponents() == 0) {
            winner = 2;
            break;
        }
    }
    
    if (winner == 1) {
        printTwoFields(fieldOne, fieldTwo);
        std::cout << "Congratulations, Player One wins!";
    } else {
        printTwoFields(fieldTwo, fieldOne);
        std::cout << "Congratulations, Player One wins!";
    }

    return 0;
}
