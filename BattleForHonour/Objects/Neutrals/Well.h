#ifndef BATTLEFORHONOUR_WELL_H
#define BATTLEFORHONOUR_WELL_H


#include "NeutralObject.h"
#include "NeutralObjectStrategy.h"

class Well: public NeutralObject {


protected:

    void print(std::ostream &stream) const override{

        stream << "WL";

    }

public:

    void applyTo(Unit &unit) override {

        unit.heal(10*strategy->getUnitTypeFactor());

    }

};


#endif //BATTLEFORHONOUR_WELL_H
