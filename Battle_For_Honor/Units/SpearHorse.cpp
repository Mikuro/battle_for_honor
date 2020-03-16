//
// Created by anton on 02.03.2020.
//

#include "SpearHorse.h"

SpearHorse::SpearHorse(int x, int y)
{
    Unit::setX(x);
    Unit::setY(y);
    Unit::setHealth(200);
    getStats().getDamage().set_type("pierce");
    getStats().getArmour().set_type("medium");
    Unit::setDistance(1);
    setSpeed(5);
    setSymbol('H');
}