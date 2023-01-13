#include "Field.cpp"

#include <stdlib.h>
#include <iostream>

void printTwoFields(Field p1, Field p2) {
    p2.printFogField();
    p1.printField();
}

int main() {
    Field fieldOne;
    Field fieldTwo;

    int winner = 0;

    fieldOne.shoot(fieldTwo);
    fieldTwo.printField();

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

    system("clear");
    system("cls");

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

    while (winner == 0) {
        //turn player one
        printTwoFields(fieldOne, fieldTwo);
        fieldOne.shoot(fieldTwo);
        if (fieldTwo.getShipComponents() == 0) {
            winner = 1;
        }
        if (winner != 0) {
            break;
        }
        //turn player two
        printTwoFields(fieldTwo, fieldOne);
        fieldOne.shoot(fieldOne);
        if (fieldOne.getShipComponents() == 0) {
            winner = 2;
        }
        if (winner != 0) {
            break;
        }
    }
    
    if (winner == 1) {
        std::cout << "Congratulations, Player One wins!";
    } else {
        std::cout << "Congratulations, Player One wins!";
    }

    return 0;
}
