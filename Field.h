#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    bool shootPos(int, int);
    void printField();
    int countShipsHit;

    private:
    char field[10][10];

};

#endif