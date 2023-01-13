#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    bool shootPos(int, int);
    void placeShip(int, int, int, int);
    void printField();
    int countShipsHit;
    char field[10][10];

};

#endif