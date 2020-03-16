//
// Created by anton on 02.03.2020.
//

#include "Swordsman.h"

Swordsman::Swordsman(int x, int y){
    Unit::setX(x);
    Unit::setY(y);
    Unit::setHealth(100);
    getStats().getDamage().set_type("light");
    getStats().getArmour().set_type("light");
    Unit::setDistance(1);
    setSpeed(1);
    setSymbol('S');
}
