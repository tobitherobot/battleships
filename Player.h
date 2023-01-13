#ifndef PLAYER
#define PLAYER

#include "Field.cpp"

class Player {
    public:
    Player() {};
    ~Player() {};
    virtual bool doTurn() = 0;
    virtual void placeShips() = 0;
    Field getField() { return field;};

    private:
    void placeSingleShip(int, int, int, int, int);
    Field field;
};

class PlayerLocal : public Player {
    public:
    PlayerLocal() : Player() {};
    void placeShips() override {
        // TODO
        std::cout << "local player placed ships" << std::endl;
    }
    bool doTurn() override {
        // TODO
        std::cout << "local player done turn" << std::endl;
        return false;
    }
    void placeSingleShip(int firstPosX, int firstPosY, int secondPosX, int secondPosY, int shipLength) {
        // TODO
    }
};

class PlayerAI : public Player {
    public:
    PlayerAI() : Player() {};
    void placeShips() override {
        // TODO
        std::cout << "ai player placed ships" << std::endl;
    }
    bool doTurn() override {
        // TODO
        std::cout << "ai player done turn" << std::endl;
        return false;
    }
    void placeSingleShip(int firstPosX, int firstPosY, int secondPosX, int secondPosY, int shipLength) {
        // TODO
    }
};

#endif