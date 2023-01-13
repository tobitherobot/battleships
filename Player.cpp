#include <iostream>
#include <strings>
#include <Player.h>

Player::Player() {

}

void Player::placeShips() {

    int shipLengths[] = {5,4,3,3,2};

}

void Player::doTurn() {

    std::string input;
    std::cout << "Enter your position, where you want to shoot: (A1 - J10)" << std::endl;

    do {
        std::cin >> input;
    } while (!checkValidInput(input));

}

void Player::printPlayer() {

}

void Player::placeSingleShip(int shipLength) {

}

bool Player::checkPlacePos(char row1, int col1, char row2, int col2, int shipLength) {

}

bool Player::checkValidInput(std::string input) {

    char row = input[0];
    int col = (int) input.substr(1)

    // position is out of bounds
    if (coords[0] < 0 || coords[0] > 9 || coords[1] < 0 || coords[1] > 9) {
        return false;
    }

    // TODO check if position has already been shot
    return true;
}

int* Player::posToCoords(char row, int col) {
    
    int coords[2];
    coords[0] = (int) (row - 'A');
    coords[1] = col - 1;
    return coords;
}

