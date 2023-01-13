#ifndef PLAYER
#define PLAYER

#include "Field.cpp"

class Player {
    public:
    Player() {};
    ~Player() {};
    virtual bool doTurn() = 0;
    virtual void enterShips() = 0;
    Field getField() { return field;};

    private:
    void placeSingleShip(int);
    Field field;
};

class PlayerLocal : public Player {
    public:
    PlayerLocal() : Player() {};
    void enterShips() override {
        int shipLengths[5] = {5,4,3,3,2};
        for (int shipLength : shipLengths) {
            enterShip(shipLength);
        }
        std::cout << "Placed all ships" << std::endl;
    }
    void enterShip(int shipLength) {

        int firstPosX;
        int firstPosY;
        int secondPosX;
        int secondPosY;
        std::string input;

        while (true) {
            std::cout << "Enter your coordinates for ship of length " << shipLength << ":" << std::endl;
            std::cin >> input;
            
            int firstPosX = (int) (input.at(0) - 'A');
            int firstPosY = (int) (input.at(1) - '1');
            int secondPosX = (int) (input.at(3) - 'A');
            int secondPosY = (int) (input.at(4) - '1');

            if (firstPosX < 0 || firstPosX > 9 || firstPosY < 0 || firstPosY > 9 || secondPosX < 0 || secondPosX > 9 || secondPosY < 0 || secondPosY > 9) {
                std::cout << "Your input " << input << " is incorrect! Please try again!" << std::endl;
                continue;
            }
            else if (firstPosX != secondPosX && firstPosY != secondPosY) {
                std::cout << "Your coordinates " << input << " are not in one row/column! Please try again!" << std::endl;
                continue;
            }
            else if (abs(firstPosX - firstPosY) + abs(secondPosX - secondPosY) + 1 != shipLength) {
                std::cout << "Your input " << input << " is not length " << shipLength << "! Please try again!" << std::endl;
                continue;
            }
            else break; // TODO check if ship is already placed in the way
        }

        getField().placeShip(std::min(firstPosX, secondPosX), std::min(firstPosY, secondPosY), std::max(firstPosX, secondPosX), std::max(firstPosY, secondPosY));
    }
    bool doTurn() override {
        // TODO
        std::string x;
        std::cin >> x;
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
    void enterShips() override {
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