#include <iostream>

#include "Game.h"
#include "CppRandom.h"

Game::Game() {}

void Game::start() {

    // welcome greeting when application starts
    greeting();
    // select if one or two players are playing
    chooseMode();

    // both players place their ships
    std::cout << "Player 1, please place your ships." << std::endl;
    std::cout << std::endl;
    player1->enterShips();

    clearConsole();

    std::cout << "Player 2, please place your ships." << std::endl;
    std::cout << std::endl;
    player2->enterShips();

    // random player, who begins the game, is chosen
    int playerBegins = GetRandomNumberBetween(1, 2);
    if (playerBegins == 1) {
        currentPlayer = player1;
        currentOpponent = player2;
    }
    else {
        currentPlayer = player2;
        currentOpponent = player1;
    }

    // main game loop
    do 
    {
        clearConsole();

        if (currentPlayer == player1) {
            std::cout << "Player 1, it's your turn!" << std::endl;
            std::cout << std::endl;
        } 
        else {
            std::cout << "Player 2, it's your turn!" << std::endl;
            std::cout << std::endl;
        } 

        bool didTurnHit;
        
        // player makes his turn, can shoot again if he hit a ship
        do 
        {
            didTurnHit = currentPlayer->doTurn(currentOpponent->field);

            // check if all ships have been sunken
            if (didTurnHit) {
                if (currentOpponent->field->countShipsHit == 17) {
                    win();
                    break;
                }
            }

            if (currentPlayer == player1) {
                std::cout << "Player 1 shot and " << (didTurnHit ? "hit a ship, it's Player 1's turn again!" : "missed!") << std::endl;
                std::cout << std::endl;
            } else  {
                std::cout << "Player 2 shot and " << (didTurnHit ? "hit a ship, it's Player 2's turn again!" : "missed!") << std::endl;
                std::cout << std::endl;
            }
        }
        while (didTurnHit);

        if (typeid(currentPlayer) == typeid(PlayerLocal)) {
            std::cout << "Press enter to end turn:";
            std::cin.ignore();
        }

        // switching roles of current player and current opponent 
        if (currentPlayer == player1) {
            currentPlayer = player2;
            currentOpponent = player1;
        }
        else {
            currentPlayer = player1;
            currentOpponent = player2;
        }

        // is game over check
        isGameOver = player1->field->countShipsHit == 17 || player2->field->countShipsHit == 17;
    }
    while (!isGameOver);
}

// one or two player mode is selected
void Game::chooseMode() {

    std::string inputMode;
    bool correctInput = false;

    do {
        std::cout << "What mode would you like to play in?" << std::endl;
        std::cout << "> [1] Player Mode (against AI opponent)" << std::endl;
        std::cout << "> [2] Player Mode (against local player)" << std::endl;
        std::cout << "> [0] AI Mode (AI against AI)" << std::endl;
        std::cout << "> [quit] Quit the game" << std::endl;
        std::cin >> inputMode;
        std::cin.ignore();

        if (!inputMode.compare("1") || !inputMode.compare("2") || !inputMode.compare("0") || !inputMode.compare("quit")) correctInput = true;
        else std::cout << "ERROR: Your input '" << inputMode << "' couldn't be interpreted! Please try again!" << std::endl;
    }
    while (!correctInput);

    if (!inputMode.compare("1")) {
        // mode 1: local player plays against an ai opponent
        player1 = new PlayerLocal;
        player2 = new PlayerAI;
        mode = 1;
        std::cout << "Playing with 1 Player!" << std::endl;
    }
    else if (!inputMode.compare("2")) {
        // mode 2: two local players take turns and play against each other
        player1 = new PlayerLocal;
        player2 = new PlayerLocal;
        mode = 2;
        std::cout << "Playing with 2 Players!" << std::endl;
    } else if (!inputMode.compare("quit")) {
        // quit the game
        exit(0);
    }
    else {
        // small easter egg: mode 0 makes two ai players play against each other
        player1 = new PlayerAI;
        player2 = new PlayerAI;
        mode = 0;
        std::cout << "Playing with 0 Players lol" << std::endl;
    }
}

void Game::win() {

    if (currentPlayer == player1) {
        std::cout << "! PLAYER 1 HAS WON !" << std::endl;
        std::cout << "Player 1 Field:" << std::endl;
        currentPlayer->field->printField();
        std::cout << "Player 2 Field:" << std::endl;
        currentOpponent->field->printField();
        std::cout << "! PLAYER 1 HAS WON !" << std::endl;
    }
    else {
        std::cout << "! PLAYER 2 HAS WON !" << std::endl;
        std::cout << "Player 2 Field:" << std::endl;
        currentPlayer->field->printField();
        std::cout << "Player 1 Field:" << std::endl;
        currentOpponent->field->printField();
        std::cout << "! PLAYER 2 HAS WON !" << std::endl;
    }

    std::string input;
    bool isCorrectInput = false;

    do {
        std::cout << "Would you like to start a [new] game or [quit]?" << std::endl;
        std::cin >> input;
        std::cin.ignore();

        if (!input.compare("new") || !input.compare("quit")) {
            isCorrectInput = true;
        }
        else std::cout << "ERROR: Your input '" << input << "' couldn't be interpreted! Please try again!" << std::endl;
    }
    while (!isCorrectInput);

    if (!input.compare("new")) this->start();
}

void Game::greeting() {

    std::cout << "Welcome to BATTLESHIPS" << std::endl;
}

void Game::clearConsole() {
    for (int i = 0; i < 50; i++) {
        std::cout << std::endl;
    }
}