#ifndef BATTLEFORHONOUR_HERMIT_H
#define BATTLEFORHONOUR_HERMIT_H


#include "Druid.h"
#include "../../../Weapon/AbolishMagic.h"

class Hermit: public Druid{

public:
    Hermit():
        Druid(*WeaponFlyWeight::getFlyWeight<AbolishMagic>(), 100){}
};

#endif //BATTLEFORHONOUR_HERMIT_H
