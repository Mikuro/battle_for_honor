#ifndef BATTLEFORHONOUR_TENT_H
#define BATTLEFORHONOUR_TENT_H


#include "NeutralObject.h"

class Tent: public NeutralObject {

protected:

    void print(std::ostream &stream) const override{

        stream << "TT";

    }

public:

    void applyTo(Unit &unit) override {

        unit.heal(50*strategy->getUnitTypeFactor());

    }

};


#endif //BATTLEFORHONOUR_TENT_H
