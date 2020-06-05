#ifndef BATTLEFORHONOUR_SPEARMAN_H
#define BATTLEFORHONOUR_SPEARMAN_H


#include "Infantry.h"
#include "../../../Weapon/Spear.h"

class SpearMan: public Infantry{

public:

    SpearMan():
        Infantry(*WeaponFlyWeight::getFlyWeight<Spear>(), 50){}


};


#endif //BATTLEFORHONOUR_SPEARMAN_H
