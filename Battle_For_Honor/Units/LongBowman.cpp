//
// Created by anton on 02.03.2020.
//

#include "LongBowman.h"

LongBowman::LongBowman(int x, int y){
    Unit::setX(x);
    Unit::setY(y);
    Unit::setHealth(50);
    getStats().getDamage().set_type("pierce");
    getStats().getArmour().set_type("light");
    Unit::setDistance(7);
    setSpeed(2);
    setSymbol('L');
}