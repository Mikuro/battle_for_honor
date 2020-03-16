//
// Created by anton on 16.03.2020.
//

#ifndef BATTLE_FOR_HONOR_UNITFACTORY_H
#define BATTLE_FOR_HONOR_UNITFACTORY_H


#include "../Units/Unit.h"

class UnitFactory{
public:
    virtual Unit *create_classic() = 0;
    virtual Unit *create_pierce() = 0;
    virtual Unit *create_hard() = 0;
};


#endif //BATTLE_FOR_HONOR_UNITFACTORY_H
