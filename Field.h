#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    char charField[10][10];
    int countShipsHit;

    bool shootAt(int, int);
    Field* placeShip(int, int, int, int);
    void printField();
    void printFog();
};

#endif