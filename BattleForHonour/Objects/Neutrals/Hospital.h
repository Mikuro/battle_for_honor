#ifndef BATTLEFORHONOUR_HOSPITAL_H
#define BATTLEFORHONOUR_HOSPITAL_H


#include "NeutralObject.h"

class Hospital: public NeutralObject {


protected:

    void print(std::ostream &stream) const override{

        stream << "HP";

    }

public:

    void applyTo(Unit &unit) override {

        unit.heal((int)100*strategy->getUnitTypeFactor());

    }

};


#endif //BATTLEFORHONOUR_HOSPITAL_H
