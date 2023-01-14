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

    void enterShip(int shipLength) override 
    {
        std::string input;
        int minX;
        int minY;
        int maxX;
        int maxY;
        bool inputCorrect = false;

        while (!inputCorrect) 
        {
            std::cout << "Enter your coordinates for ship of length " << shipLength << ":" << std::endl;
            std::cin >> input;
            std::cin.ignore();
            inputCorrect = true;
            
            int firstPosX = int(toupper(input.at(0)) - 65);
            int firstPosY = atoi(input.substr(1, input.find('-')).c_str()) - 1;
            int secondPosX = int(toupper(input.at(input.find('-')+1)) - 65);
            int secondPosY = atoi(input.substr(input.find('-')+2).c_str()) - 1;

            if (firstPosX < 0 || firstPosX > 9 || firstPosY < 0 || firstPosY > 9 || secondPosX < 0 || secondPosX > 9 || secondPosY < 0 || secondPosY > 9) {
                std::cout << "ERROR: Your input " << input << " is incorrect! Please try again!" << std::endl;
                inputCorrect = false;
                continue;
            }
            else if (firstPosX != secondPosX && firstPosY != secondPosY) {
                std::cout << "ERROR: Your coordinates " << input << " are not in one row/column! Please try again!" << std::endl;
                inputCorrect = false;
                continue;
            }
            else if (abs(firstPosX - secondPosX) + abs(firstPosY - secondPosY) + 1 != shipLength) {
                std::cout << "ERROR: Your input " << input << " is not length " << shipLength << "! Please try again!" << std::endl;
                inputCorrect = false;
                continue;
            }
            
            minX = std::min(firstPosX, secondPosX);
            minY = std::min(firstPosY, secondPosY);
            maxX = std::max(firstPosX, secondPosX);
            maxY = std::max(firstPosY, secondPosY);

            for (int i = minX; i <= maxX; i++) {
                for (int j = minY; j <= maxY; j++) {
                    if (field->isShipAround(i, j)) {
                        std::cout << "ERROR: Your coordinates overlap with / touch previous set ships! Please try again!" << std::endl;
                        inputCorrect = false;
                        break;
                    }
                }
                if (!inputCorrect) break;
            }
        }

        field->placeShip(minX, minY, maxX, maxY);
        field->printField();
    }

    bool doTurn(Field* opponentField) override 
    {
        int posX;
        int posY;
        std::string input;
        bool inputCorrect = false;

        while (!inputCorrect) 
        {
            std::cout << "Enter your coordinates for the field you want to shoot:" << std::endl;
            std::cin >> input;
            std::cin.ignore();

            inputCorrect = true;
            
            posX = int(toupper(input.at(0)) - 65);
            posY = atoi(input.substr(1, input.find('-')).c_str()) - 1;

            if (posX < 0 || posX > 9 || posY < 0 || posY > 9) {
                std::cout << "ERROR: Your input " << input << " is incorrect! Please try again!" << std::endl;
                inputCorrect = false;
                continue;
            }
            else if (opponentField->charAt(posX, posY) == 'X' || opponentField->charAt(posX, posY) == 'M') {
                std::cout << "ERROR: Your input " << input << " has already been shot! Please try again!" << std::endl;
                inputCorrect = false;
                continue;
            }
        }

        bool hasHit = opponentField->shootAt(posX, posY);
        opponentField->printFog();
        if (opponentField->isShipSunk(posX, posY)) std::cout << "! SHIP SUNK !" << std::endl;

        return hasHit;
    }

    void enterShips() override 
    {
        int shipLengths[5] = {5,4,3,3,2};
        for (int shipLength : shipLengths) {
            enterShip(shipLength);
        }
    }
};

// ai player is not controller by input, works/thinks for itself
class PlayerAI : public Player {
    public:
    PlayerAI() : Player() {
        field = new Field();
    };

    void enterShip(int shipLength) override 
    {
        int minX;
        int minY;
        int maxX;
        int maxY;
        bool inputCorrect = false;

        while (!inputCorrect) 
        {
            inputCorrect = true;
            
            int firstPosX = GetRandomNumberBetween(0, 9);
            int firstPosY = GetRandomNumberBetween(0, 9);
            int secondPosX;
            int secondPosY;

            // 0=up, 1=right, 2=down, 3=left
            int direction = GetRandomNumberBetween(0, 3);

            if (direction == 0) {
                secondPosX = firstPosX - shipLength + 1;
                secondPosY = firstPosY;
            }
            else if (direction == 1) {
                secondPosX = firstPosX;
                secondPosY = firstPosY + shipLength - 1;
            }
            else if (direction == 2) {
                secondPosX = firstPosX + shipLength - 1;
                secondPosY = firstPosY;
            }
            else {
                secondPosX = firstPosX;
                secondPosY = firstPosY - shipLength + 1;
            }

            if (firstPosX < 0 || firstPosX > 9 || firstPosY < 0 || firstPosY > 9 || secondPosX < 0 || secondPosX > 9 || secondPosY < 0 || secondPosY > 9) {
                inputCorrect = false;
                continue;
            }
            
            minX = std::min(firstPosX, secondPosX);
            minY = std::min(firstPosY, secondPosY);
            maxX = std::max(firstPosX, secondPosX);
            maxY = std::max(firstPosY, secondPosY);

            for (int i = minX; i <= maxX; i++) {
                for (int j = minY; j <= maxY; j++) {
                    if (field->isShipAround(i, j)) {
                        inputCorrect = false;
                        break;
                    }
                }
            }
        }

        field->placeShip(minX, minY, maxX, maxY);
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

        bool hasHit = opponentField->shootAt(posX, posY);
        opponentField->printFog();
        return hasHit;
    }

    void enterShips() override 
    {
        int shipLengths[5] = {5,4,3,3,2};
        for (int shipLength : shipLengths) {
            enterShip(shipLength);
        }
        std::cout << "AI Player placed all his ships!" << std::endl;
    }
};

#endif