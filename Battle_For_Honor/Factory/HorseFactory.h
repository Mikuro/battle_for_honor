//
// Created by anton on 16.03.2020.
//

#ifndef BATTLE_FOR_HONOR_HORSEFACTORY_H
#define BATTLE_FOR_HONOR_HORSEFACTORY_H


#include "UnitFactory.h"
#include "../Units/HorseArcher.h"
#include "../Units/SpearHorse.h"

class HorseFactory : UnitFactory{
public:
    SpearHorse * create_classic(int x, int y){
        return new SpearHorse(x, y);
    }
    HorseArcher * create_pierce(int x, int y){
        return new HorseArcher(x, y);
    }
};


#endif //BATTLE_FOR_HONOR_HORSEFACTORY_H
