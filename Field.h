#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    char checkPos(int, int);
    void printField();
    bool checkSurroundings(int, int);
    void placeShip(int);

    private:
    char field[10][10];

};

#endif