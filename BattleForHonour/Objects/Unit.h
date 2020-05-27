#ifndef BATTLEFORHONOUR_UNIT_H
#define BATTLEFORHONOUR_UNIT_H


#include <vector>
#include <ostream>
#include "../Armor/Armor.h"
#include "../Weapon/Weapon.h"
#include "../Observers/Observers.h"
#include "../Point.h"
#include "GameObject.h"
#include "../Landscapes/LandscapeProxy.h"
#include "Neutrals/NeutralObject.h"

#include "../Logs/log.h"

enum class UnitType{

    INFANTRY,
    DRUID,
    ARCHER

};

class Unit: public GameObject {

protected:

    std::vector<UnitObserver*> observers;

    UnitType unitType;

    Armor &armor;
    Weapon &weapon;
    int health;

    void print(std::ostream &stream) const override;

public:

    Unit(const Unit &other);
    Unit(UnitType unitType, Armor &armor, Weapon &weapon, int health);

    Weapon &getWeapon(){ return weapon; }
    Armor &getArmor(){ return armor; }

    void move(Point position);
    void attack(Unit &other);
    void damage(int damage);
    void heal(int hp);

    void addObserver(UnitObserver *observer);
    Unit& operator=(const Unit &other);
    Unit& operator<<(NeutralObject *neutralObject);

    friend LogProxy& operator<<(LogProxy &logger, Unit &unit){

        logger << "Unit( x: " << unit.position.x << " y: " << unit.position.y << " health: " << unit.health << ")";
        return logger;

    }

    UnitType getUnitType(){ return unitType; }

    int getHealth();

};


#endif //BATTLEFORHONOUR_UNIT_H
