#ifndef BATTLEFORHONOUR_ARMOR_H
#define BATTLEFORHONOUR_ARMOR_H

#include <ostream>

enum class ArmorType{
    LIGHT,
    MEDIUM,
    HEAVY,
    MAGIC
};

class Armor {

protected:

    ArmorType type;
    int damageAbsorption;

public:

    Armor(){}
    int getDamageAbsorption() const { return damageAbsorption; }
    ArmorType getType(){ return type; }

    bool operator==(Armor &other){

        return type == other.type && damageAbsorption == other.damageAbsorption;

    }

    Armor& operator=(const Armor& other){

        if (this == &other) return *this;
        type = other.type;
        damageAbsorption = other.damageAbsorption;
        return *this;

    }

    friend std::ostream &operator<<(std::ostream &stream, const Armor &armor){

        stream << "Armor( " << "Damage Absorption: " << armor.damageAbsorption << " )";
        return stream;

    }

};


#endif //BATTLEFORHONOUR_ARMOR_H
