#ifndef BATTLEFORHONOUR_LEATHERARMOR_H
#define BATTLEFORHONOUR_LEATHERARMOR_H


#include "Armor.h"

class LeatherArmor: public Armor {

public:
    LeatherArmor(){
        damageAbsorption = 3;
        type = ArmorType::LIGHT;
    }

};


#endif //BATTLEFORHONOUR_LEATHERARMOR_H
