//
// Created by anton on 16.03.2020.
//

#ifndef BATTLE_FOR_HONOR_FOOTMANFACTORY_H
#define BATTLE_FOR_HONOR_FOOTMANFACTORY_H


#include "../Units/Swordsman.h"
#include "UnitFactory.h"
#include "../Units/Spearman.h"

class FootmanFactory : UnitFactory{
public:
    Swordsman * create_classic(int x, int y){
        return new Swordsman(x, y);
    }
    Spearman * create_pierce(int x, int y){
        return new Spearman(x, y);
    }
};


#endif //BATTLE_FOR_HONOR_FOOTMANFACTORY_H
