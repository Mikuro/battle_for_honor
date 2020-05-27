#ifndef BATTLEFORHONOUR_ARCHER_H
#define BATTLEFORHONOUR_ARCHER_H


#include "../../../Weapon/Bow.h"
#include "../../Unit.h"
#include "../../../Weapon/WeaponFlyWeight.h"
#include "../../../Armor/ArmorFlyWeight.h"

class Archer: public Unit{

public:
    Archer(Armor &armor, int health): Unit(UnitType::ARCHER, armor,*WeaponFlyWeight::getFlyWeight<Bow>(), health){}
};


#endif //BATTLEFORHONOUR_ARCHER_H
