#ifndef BATTLE_FOR_HONOR_UNIT_H
#define BATTLE_FOR_HONOR_UNIT_H


#include "Attributes.h"

class Unit{
private:
    Attributes stats;
    int x;
    int y;
    int health;
    int distance;
    int speed;
    char symbol;
public:
    Unit();
    int getX();
    int getY();
    int getHealth();
    int getDistance();
    Attributes getStats();
    void setDistance(int distance);
    void setX(int);
    void setY(int);
    void setHealth(int);
    void setStats(Attributes);
    int getSpeed();
    char getSymbol();
    void setSpeed(int speed);
    void setSymbol(char symbol);

};


#endif //BATTLE_FOR_HONOR_UNIT_H
