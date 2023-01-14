#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    char checkPos(int, int);
    void setPos(int, int, char);
    void printField();
    void printFogField();
    bool checkSurroundings(int, int);
    void placeShip(int);
    int charToInt(char);
    void shoot(Field &enemy);
    void reduceShipComponents();
    int getShipComponents();
    void removeHitComponent(Field &enemy, int, int);

    bool third;
    int ship5[5][2];
    int ship4[4][2];
    int ship3[3][2];
    int ship32[3][2];
    int ship2[2][2];

    private:
    char field[10][10];
    int shipComponents;
};

#endif