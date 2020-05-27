#ifndef BATTLEFORHONOUR_ROBE_H
#define BATTLEFORHONOUR_ROBE_H


#include "Armor.h"

class Robe: public Armor{

public:
    Robe(){

        damageAbsorption = 1;
        type = ArmorType::MAGIC;

    }

};


#endif //BATTLEFORHONOUR_ROBE_H
