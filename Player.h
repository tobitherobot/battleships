#ifndef PLAYER
#define PLAYER

#include <algorithm>

#include "Field.cpp"
#include "CppRandom.h"

class Player {
    public:
    Player() {};
    ~Player() {};
    virtual bool doTurn(Field* opponentField) = 0;
    virtual void enterShips() = 0;
    Field* field;

    private:
    virtual void enterShip(int) = 0;
};

class PlayerLocal : public Player {
    public:
    PlayerLocal() : Player() {
        field = new Field();
    };

    void enterShips() override 
    {
        int shipLengths[5] = {5,4,3,3,2};
        for (int shipLength : shipLengths) {
            enterShip(shipLength);
        }
        std::cout << "Placed all ships" << std::endl;
    }

    void enterShip(int shipLength) override 
    {
        int firstPosX;
        int firstPosY;
        int secondPosX;
        int secondPosY;
        std::string input;

        while (true) {
            std::cout << "Enter your coordinates for ship of length " << shipLength << ":" << std::endl;
            std::cin >> input;
            
            firstPosX = int(toupper(input.at(0)) - 65);
            firstPosY = atoi(input.substr(1, input.find('-')).c_str()) - 1;
            secondPosX = int(toupper(input.at(input.find('-')+1)) - 65);
            secondPosY = atoi(input.substr(input.find('-')+2).c_str()) - 1;

            if (firstPosX < 0 || firstPosX > 9 || firstPosY < 0 || firstPosY > 9 || secondPosX < 0 || secondPosX > 9 || secondPosY < 0 || secondPosY > 9) {
                std::cout << "Your input " << input << " is incorrect! Please try again!" << std::endl;
                continue;
            }
            else if (firstPosX != secondPosX && firstPosY != secondPosY) {
                std::cout << "Your coordinates " << input << " are not in one row/column! Please try again!" << std::endl;
                continue;
            }
            else if (abs(firstPosX - secondPosX) + abs(firstPosY - secondPosY) + 1 != shipLength) {
                std::cout << "Your input " << input << " is not length " << shipLength << "! Please try again!" << std::endl;
                continue;
            }
            else if (false) {
                // TODO check if ship is already placed in the way
            }
            else break;
        }

        field->placeShip(std::min(firstPosX, secondPosX), std::min(firstPosY, secondPosY), std::max(firstPosX, secondPosX), std::max(firstPosY, secondPosY));
        field->printField();
    }

    bool doTurn(Field* opponentField) override 
    {
        int posX;
        int posY;
        std::string input;

        while (true) {
            std::cout << "Enter your coordinates for the field you want to shoot:" << std::endl;
            std::cin >> input;
            
            posX = int(toupper(input.at(0)) - 65);
            posY = atoi(input.substr(1, input.find('-')).c_str()) - 1;

            if (posX < 0 || posX > 9 || posY < 0 || posY > 9) {
                std::cout << "Your input " << input << " is incorrect! Please try again!" << std::endl;
                continue;
            }
            else if (false) {
                // TODO check if field has already been shot
            }
            else break;
        }

        bool hasHit = opponentField->shootAt(posX, posY);
        opponentField->printFog();

        return hasHit;
    }
};

// ai player is not controller by input, works/thinks for itself
class PlayerAI : public Player {
    public:
    PlayerAI() : Player() {
        field = new Field();
    };

    void enterShip(int shipLength) override {
        // TODO
    }

    // ai player shoots at random location
    bool doTurn(Field* opponentField) override 
    {
        int posX;
        int posY;
        bool isCorrectPos;

        do {
            posX = GetRandomNumberBetween(0, 9);
            posY = GetRandomNumberBetween(0, 9);

            // if field has been shot at previously (miss or hit), repeat random
            if (opponentField->charAt(posX, posY) == 'X' || opponentField->charAt(posX, posY) == 'M') {
                isCorrectPos = false;
            }
            else isCorrectPos = true;
        }
        while (!isCorrectPos);

        opponentField->shootAt(posX, posY);
    }

    void enterShips() override 
    {
        int shipLengths[5] = {5,4,3,3,2};
        for (int shipLength : shipLengths) {
            enterShip(shipLength);
        }
        std::cout << "Placed all ships" << std::endl;
    }
};

#endif