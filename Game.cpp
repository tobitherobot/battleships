#include <iostream>

#include "Game.h"
#include "CppRandom.h"

Game::Game() {}

void Game::start() {

    std::cout << "Welcome" << std::endl;

    // select if one or two players are playing
    chooseMode();

    // both players place their ships
    player1->enterShips();
    player2->enterShips();

    // random player, who begins the game, is chosen
    int playerBegins = GetRandomNumberBetween(1, 2);
    if (playerBegins == 1) {
        std::cout << "Player 1 begins!" << std::endl;
        currentPlayer = player1;
        currentOpponent = player2;
    }  
    else {
        std::cout << "Player 2 begins!" << std::endl;
        currentPlayer = player2;
        currentOpponent = player1;
    }

    // main game loop
    do {
        // clear console
        std::system("cls");

        if (currentPlayer == player1) std::cout << "Player 1, it's your turn!" << std::endl;
        else std::cout << "Player 2, it's your turn!" << std::endl;

        bool didTurnHit;
        
        // player makes his turn, can shoot again if he hit a ship
        do 
        {
            didTurnHit = currentPlayer->doTurn(currentOpponent->field);

            if (currentPlayer == player1) std::cout << "Player 1 shot and " << (didTurnHit ? " hit a ship, it's Player 1's turn again!" : "missed!") << std::endl;
            else std::cout << "Player 2 shot and " << (didTurnHit ? " hit a ship, it's Player 2's turn again!" : "missed!") << std::endl;
        } 
        while (didTurnHit);
        
        // switching roles of current player and current opponent 
        if (currentPlayer == player1) {
            currentPlayer = player2;
            currentOpponent = player1;
        }
        else {
            currentPlayer = player1;
            currentOpponent = player2;
        }

        currentOpponent->field->printFog();

        std::cout << "Press enter to end turn: ";
        std::cin.ignore();

        // is game over check
        isGameOver = player1->field->countShipsHit == 17 || player2->field->countShipsHit == 17;
    }
    while (!isGameOver);
}

// one or two player mode is selected
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
        // mode 1: local player plays against an ai opponent
        player1 = new PlayerLocal;
        player2 = new PlayerAI;
        mode = 1;
        std::cout << "Playing with 1 Player!" << std::endl;
    }
    else if (inputMode == 2) {
        // mode 2: two local players take turns and play against each other
        player1 = new PlayerLocal;
        player2 = new PlayerLocal;
        mode = 2;
        std::cout << "Playing with 2 Players!" << std::endl;
    }
    else {
        // small easter egg: mode 0 makes two ai players play against each other
        player1 = new PlayerAI;
        player2 = new PlayerAI;
        mode = 0;
        std::cout << "Playing with 0 Players lol" << std::endl;
    }
}
