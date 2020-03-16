//
// Created by anton on 02.03.2020.
//

#include "Crossbows.h"

Crossbows::Crossbows(int x, int y){
    Unit::setX(x);
    Unit::setY(y);
    Unit::setHealth(50);
    getStats().getDamage().set_type("pierce");
    getStats().getArmour().set_type("hard");
    Unit::setDistance(7);
    setSpeed(1);
    setSymbol('C');
}