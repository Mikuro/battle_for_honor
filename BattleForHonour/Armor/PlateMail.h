#ifndef BATTLEFORHONOUR_PLATEMAIL_H
#define BATTLEFORHONOUR_PLATEMAIL_H


#include "Armor.h"

class PlateMail: public Armor{

public:

    PlateMail(){

        damageAbsorption = 5;
        type = ArmorType::MEDIUM;

    }

};

#endif //BATTLEFORHONOUR_PLATEMAIL_H
