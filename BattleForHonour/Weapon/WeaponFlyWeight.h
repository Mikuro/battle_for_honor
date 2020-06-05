#ifndef BATTLEFORHONOUR_WEAPONFLYWEIGHT_H
#define BATTLEFORHONOUR_WEAPONFLYWEIGHT_H


#include <vector>
#include "Weapon.h"

class WeaponFlyWeight {

private:

    static WeaponFlyWeight *self;
    std::vector<Weapon*> weapons;

public:

    template <typename Type>
    static Type* getFlyWeight(){

        if (!self) self = new WeaponFlyWeight();

        Type needWeapon;
        for (auto *weapon: self->weapons){

            if (needWeapon == *weapon){
                return static_cast<Type*>(weapon);
            }
        }

        Type *tmp = new Type();
        self->weapons.push_back(tmp);
        return tmp;
    }
};


#endif //BATTLEFORHONOUR_WEAPONFLYWEIGHT_H
