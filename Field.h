#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    char checkPos(int, int);
    void setpos(int, int, char);
    void printField();
    bool checkSurroundings(int, int);
    void placeShip(int);
    void shoot(Field);
    int charToInt(char);
    void reduceShipComponents();

    private:
    char field[10][10];
    int shipComponents;

};

#endif