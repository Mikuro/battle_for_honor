//
// Created by anton on 02.03.2020.
//

#include "Attributes.h"

Attributes::Attributes(){
    armour.set_type("null");
    damage.set_type("null");
}

void Attributes::setArmour(Armour &armour) {
    this->armour = armour;
}

void Attributes::setDamage(Damage &damage) {
    this->damage = damage;
}

Armour& Attributes::getArmour() {
    return this->armour;
}
Damage& Attributes::getDamage() {
    return this->damage;
}


