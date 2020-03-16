//
// Created by anton on 02.03.2020.
//

#ifndef BATTLE_FOR_HONOR_ARMOUR_H
#define BATTLE_FOR_HONOR_ARMOUR_H


#include <string>

class Armour{
    private:
        std::string type_armour;
        int multiply = 0;
    public:
    Armour();
    Armour(std::string type);
    void set_type(std::string type_armour);
    Armour get_type();
};


#endif //BATTLE_FOR_HONOR_ARMOUR_H
