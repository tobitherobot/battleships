#ifndef FIELD
#define FIELD

class Field {
    public:
    Field();
    char checkPos(int, int);
    void printField();

    private:
    char field[10][10];

};

#endif