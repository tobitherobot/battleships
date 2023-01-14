#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    char charField[10][10];
    int countShipsHit;

    bool shootAt(int, int);
    Field* placeShip(int, int, int, int);
    bool isShipSunk(int, int);
    bool isShipSunkRecursive(int, int, int);
    bool isShipAround(int, int);
    void printField();
    void printFog();
    char charAt(int, int);
};

#endif