#ifndef BATTLEFORHONOUR_SWORDMAN_H
#define BATTLEFORHONOUR_SWORDMAN_H


#include "Infantry.h"
#include "../../../Weapon/Sword.h"

class SwordMan: public Infantry{

public:

    SwordMan(): Infantry(*WeaponFlyWeight::getFlyWeight<Sword>(), 100){}

};


#endif //BATTLEFORHONOUR_SWORDMAN_H
