//
//
//

#include "Base.h"

Base::Base(int x, int y){
    this->setHealth(1000);
    this->setArmour("siege");
    this->setDamage("light");
    this->setDistance(5);
    this->setSpeed(0);
    this->setX(x);
    this->setY(y);
    this->setSymbol(222);
}