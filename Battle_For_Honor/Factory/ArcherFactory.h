//
// Created by anton on 16.03.2020.
//

#ifndef BATTLE_FOR_HONOR_ARCHERFACTORY_H
#define BATTLE_FOR_HONOR_ARCHERFACTORY_H


#include "UnitFactory.h"
#include "../Units/Crossbows.h"
#include "../Units/LongBowman.h"

class ArcherFactory : UnitFactory{
public:
    Crossbows* create_hard(int x, int y){
        return new Crossbows(x, y);
    }
    LongBowman * create_pierce(int x, int y){
        return new LongBowman(x, y);
    }
};


#endif //BATTLE_FOR_HONOR_ARCHERFACTORY_H
