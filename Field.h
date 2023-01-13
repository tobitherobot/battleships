#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    char checkPos(int, int);
    void setpos(int, int, char);
    void printField();
    void printFogField();
    bool checkSurroundings(int, int);
    void placeShip(int);
    int charToInt(char);
    void shoot(Field);
    void reduceShipComponents();

    private:
    char field[10][10];
    int shipComponents;

};

#endif