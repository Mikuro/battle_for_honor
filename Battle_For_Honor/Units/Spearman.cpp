//
// Created by anton on 02.03.2020.
//

#include "Spearman.h"

Spearman::Spearman(int x, int y)
{
    Unit::setX(x);
    Unit::setY(y);
    Unit::setHealth(100);
    getStats().getDamage().set_type("pierce");
    getStats().getArmour().set_type("light");
    Unit::setDistance(1);
    setSpeed(1);
    setSymbol(180);
}