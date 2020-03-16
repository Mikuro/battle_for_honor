#ifndef BATTLE_FOR_HONOR_ATTRIBUTES_H
#define BATTLE_FOR_HONOR_ATTRIBUTES_H


#include "Damage.h"
#include "Armour.h"

class Attributes{


private:
    Armour armour;
    Damage damage;
public:
    Attributes();
    void setArmour(Armour &armour);
    void setDamage(Damage &damage);
    Armour &getArmour();
    Damage &getDamage();

};
#endif //BATTLE_FOR_HONOR_ATTRIBUTES_H
