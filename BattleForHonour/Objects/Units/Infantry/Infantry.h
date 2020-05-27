#ifndef BATTLEFORHONOUR_INFANTRY_H
#define BATTLEFORHONOUR_INFANTRY_H


#include "../../Unit.h"
#include "../../../Armor/PlateMail.h"
#include "../../../Weapon/WeaponFlyWeight.h"
#include "../../../Armor/ArmorFlyWeight.h"

class Infantry: public Unit {

public:

    Infantry(Weapon &weapon, int health): Unit(UnitType::INFANTRY, *ArmorFlyWeight::getFlyWeight<PlateMail>(), weapon, health) {}

};


#endif //BATTLEFORHONOUR_INFANTRY_H
