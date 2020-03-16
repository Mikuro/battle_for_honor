//
// Created by anton on 02.03.2020.
//

#include "HorseArcher.h"

HorseArcher::HorseArcher(int x, int y){
    Unit::setX(x);
    Unit::setY(y);
    Unit::setHealth(70);
    getStats().getDamage().set_type("pierce");
    getStats().getArmour().set_type("light");
    Unit::setDistance(4);
    setSpeed(5);
    setSymbol('Y');
}