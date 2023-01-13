#include <iostream>

#include "Game.h"
#include "CppRandom.h"

Game::Game() {}

void Game::start() {

    std::cout << "Welcome" << std::endl;

    chooseMode();
    player1->enterShips();
    player2->enterShips();

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
        
        if (nextPlayer == player1) nextPlayer = player2;
        else nextPlayer = player1;

        isGameOver = player1->getField().countShipsHit == 17 || player2->getField().countShipsHit == 17;
    }
    while (!isGameOver);
}

void Game::chooseMode() {

    int inputMode;
    bool correctInput = false;

    do {
        std::cout << "What mode would you like to play in?" << std::endl;
        std::cout << "> [1] Player Mode (against AI opponent)" << std::endl;
        std::cout << "> [2] Player Mode (against local player)" << std::endl;
        std::cin >> inputMode;

        if (inputMode == 1 || inputMode == 2 || inputMode == 0) correctInput = true;
        else std::cout << "Couldn't understand " << inputMode << "! Please try again!" << std::endl;
    }
    while (!correctInput);

    if (inputMode == 1) {
        player1 = new PlayerLocal;
        player2 = new PlayerAI;
        mode = 1;
        std::cout << "Playing with 1 Player!" << std::endl;
    }
    else if (inputMode == 2) {
        player1 = new PlayerLocal;
        player2 = new PlayerLocal;
        mode = 2;
        std::cout << "Playing with 2 Players!" << std::endl;
    }
    else {
        player1 = new PlayerAI;
        player2 = new PlayerAI;
        mode = 0;
        std::cout << "Playing with 0 Players lol" << std::endl;
    }
}
