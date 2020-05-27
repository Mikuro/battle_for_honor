#ifndef BATTLEFORHONOUR_ARMORFLYWEIGHT_H
#define BATTLEFORHONOUR_ARMORFLYWEIGHT_H


#include <vector>
#include "Armor.h"

class ArmorFlyWeight {

private:

    static ArmorFlyWeight *self;
    std::vector<Armor*> armors;

public:
    template <typename T>
    static T* getFlyWeight(){

        if (!self)
            self = new ArmorFlyWeight();

        T needArmor;
        for (auto *armor: self->armors){

            if (needArmor == *armor){
                return static_cast<T*>(armor);
            }

        }

        T *armorPtr = new T();
        self->armors.push_back(armorPtr);
        return armorPtr;

    }

};


#endif //BATTLEFORHONOUR_ARMORFLYWEIGHT_H