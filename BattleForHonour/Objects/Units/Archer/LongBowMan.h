#ifndef BATTLEFORHONOUR_LONGBOWMAN_H
#define BATTLEFORHONOUR_LONGBOWMAN_H


#include "Archer.h"
#include "../../../Armor/PlateMail.h"

class LongBowMan: public Archer{

public:

    LongBowMan(): Archer(*ArmorFlyWeight::getFlyWeight<PlateMail>(), 50){}

};


#endif //BATTLEFORHONOUR_LONGBOWMAN_H
