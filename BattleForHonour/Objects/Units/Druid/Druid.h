#ifndef BATTLEFORHONOUR_DRUID_H
#define BATTLEFORHONOUR_DRUID_H


#include "../../Unit.h"
#include "../../../Armor/Robe.h"
#include "../../../Weapon/AbolishMagic.h"
#include "../../../Weapon/WeaponFlyWeight.h"
#include "../../../Armor/ArmorFlyWeight.h"

class Druid: public Unit{

public:

    Druid(Weapon &weapon, int health): Unit(UnitType::DRUID, *ArmorFlyWeight::getFlyWeight<Robe>(), weapon, health){}

};


#endif //BATTLEFORHONOUR_DRUID_H
