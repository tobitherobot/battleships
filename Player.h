#ifndef PLAYER
#define PLAYER

#include <Field.cpp>

class Player {
    public:
    Player();
    void placeShips();
    void doTurn();
    void printPlayer();

    private:
    Field field;
    void placeSingleShip(int);
    bool checkPlacePos(char, int, char, int, int);
    bool checkShootPos(char, int);
    int* posToCoords(char, int);
};

#endif