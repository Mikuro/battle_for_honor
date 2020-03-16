//
// Created by anton on 02.03.2020.
//

#ifndef BATTLE_FOR_HONOR_DAMAGE_H
#define BATTLE_FOR_HONOR_DAMAGE_H


#include <string>
#include <utility>


class Damage{
private:
    std::string type_damage;
    int multiply = 0;
public:
    Damage();
    Damage(std::string type);
    void set_type(std::string type_damage);
    Damage get_type();
};


#endif //BATTLE_FOR_HONOR_DAMAGE_H
