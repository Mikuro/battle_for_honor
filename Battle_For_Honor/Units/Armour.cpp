//
// Created by anton on 02.03.2020.
//

#include "Armour.h"

Armour::Armour(){
    this->set_type("null");
}
Armour::Armour(std::string type){
    type_armour = std::move(type);
}

Armour Armour::get_type() {
    return type_armour;
}

void Armour::set_type(std::string type_armour){
    if (type_armour == "light"){
        this->type_armour = "light";
        this->multiply = 5;
    }
    if (type_armour == "medium"){
        this->type_armour = "medium";
        this->multiply = 15;
    }
    if (type_armour == "hard"){
        this->type_armour = "hard";
        this->multiply = 20;
    }
    if (type_armour == "siege"){
        this->type_armour = "siege";
        this->multiply = 50;
    }
    if (type_armour == "null"){
        this->type_armour = "null";
        this->multiply = 0;
    }

}