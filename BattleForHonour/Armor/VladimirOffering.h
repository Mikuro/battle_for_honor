#ifndef BATTLEFORHONOUR_VLADIMIROFFERING_H
#define BATTLEFORHONOUR_VLADIMIROFFERING_H


#include <climits>
#include "Armor.h"

class VladimirOffering: public Armor{

public:
    VladimirOffering(){

        damageAbsorption = 10;
        type = ArmorType::HEAVY;

    }

};


#endif //BATTLEFORHONOUR_VLADIMIROFFERING_H
