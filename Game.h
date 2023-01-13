#ifndef GAME
#define GAME

#include <Player.h>

class Game {
    public:
    Game();
    void start();
    void save();

    private:
    Player player1;
    Player player2;
    Player* nextPlayer;
    void encrypt();
    void decrypt();
};

#endif