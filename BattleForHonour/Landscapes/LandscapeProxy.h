#ifndef BATTLEFORHONOUR_LANDSCAPEPROXY_H
#define BATTLEFORHONOUR_LANDSCAPEPROXY_H


#include "Landscape.h"
#include "../Point.h"

class LandscapeProxy {

private:

    Landscape *landscape;

public:

    LandscapeProxy(Landscape *landscape);

    int getDamageFactor(WeaponType type);
    int getAbsorptionFactor(ArmorType type);

};


#endif //BATTLEFORHONOUR_LANDSCAPEPROXY_H
