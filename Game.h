#ifndef GAME
#define GAME

#include "Player.h"

class Game {
    public:
    Game();
    void start();
    void save();
    void load();
    void chooseMode();

    private:
    Player* player1;
    Player* player2;
    Player* nextPlayer;
    int mode;
    void encrypt();
    void decrypt();
};

#endif