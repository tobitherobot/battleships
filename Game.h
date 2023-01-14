#ifndef GAME
#define GAME

#include "Player.h"

class Game {
    public:
    Game();
    void start();
    void chooseMode();
    void save();
    void load();

    private:
    Player* player1;
    Player* player2;
    Player* currentPlayer;
    Player* currentOpponent;
    int mode;
    bool isGameOver;
};

#endif