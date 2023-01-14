#ifndef GAME
#define GAME

#include "Player.h"

class Game {
    public:
    Game();
    void start();
    void greeting();
    void chooseMode();
    void win();
    void save();
    void load();
    void clearConsole();

    private:
    Player* player1;
    Player* player2;
    Player* currentPlayer;
    Player* currentOpponent;
    int mode;
    bool isGameOver;
};

#endif