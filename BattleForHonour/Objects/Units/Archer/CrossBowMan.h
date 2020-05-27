#ifndef BATTLEFORHONOUR_CROSSBOWMAN_H
#define BATTLEFORHONOUR_CROSSBOWMAN_H


#include "Archer.h"
#include "../../../Armor/LeatherArmor.h"

class CrossBowMan: public Archer{

public:

    CrossBowMan(): Archer( *ArmorFlyWeight::getFlyWeight<LeatherArmor>(), 100){}

};



#endif //BATTLEFORHONOUR_CROSSBOWMAN_H
