#ifndef BATTLEFORHONOUR_INFANTRYSTRATEGY_H
#define BATTLEFORHONOUR_INFANTRYSTRATEGY_H


#include "NeutralObjectStrategy.h"

class InfantryStrategy: public NeutralObjectStrategy {

public:
    int getUnitTypeFactor() override {
        return 3;
    }
};


#endif //BATTLEFORHONOUR_INFANTRYSTRATEGY_H
