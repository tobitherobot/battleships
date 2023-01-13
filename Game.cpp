#include <iostream>

#include "Game.h"
#include "CppRandom.h"

Game::Game() { }

void Game::start() {

    std::cout << "Welcome" << std::endl;

    chooseMode();
    player1->placeShips();
    player2->placeShips();

    int playerBegins = GetRandomNumberBetween(1, 2);
    if (playerBegins == 1) {
        std::cout << "Player 1 begins!" << std::endl;
        nextPlayer = player1;
    }  
    else {
        std::cout << "Player 2 begins!" << std::endl;
        nextPlayer = player2;
    }

    bool isGameOver;

    do {
        bool didTurnHit;
        
        do {
            didTurnHit = nextPlayer->doTurn();
        } while (didTurnHit);
        
        //std::cout << (nextPlayer* == player1) << " " << (nextPlayer* == player2) << std::endl;

        isGameOver = player1->getField().countShipsHit == 17 || player2->getField().countShipsHit == 17;
    }
    while (!isGameOver);
}

void Game::chooseMode() {

    std::string input;
    bool correctInput = false;

    do {
        std::cout << "What mode would you like to play in?" << std::endl;
        std::cout << "> [1] Player Mode (against AI opponent)" << std::endl;
        std::cout << "> [2] Player Mode (against local player)" << std::endl;
        std::cin >> input;

        if (input.compare("1") || input.compare("2")) correctInput = true;
        else std::cout << "Couldn't understand " << input << "! Please try again!" << std::endl;
    }
    while (!correctInput);

    if (input.compare("1")) {
        player1 = new PlayerLocal;
        player2 = new PlayerAI;
        mode = 1;
    }
    else {
        player1 = new PlayerLocal;
        player2 = new PlayerLocal;
        mode = 2;
    }
}
