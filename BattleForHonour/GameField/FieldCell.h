#ifndef BATTLEFORHONOUR_FIELDCELL_H
#define BATTLEFORHONOUR_FIELDCELL_H


#include <ostream>
#include "../Terrains/Terrain.h"
#include "../Objects/GameObject.h"

class FieldCell {

private:

    GameObject *object;
    Terrain *terrain;

public:

    FieldCell():
        object(nullptr),
        terrain(nullptr) {}

    FieldCell(const FieldCell& other);
    FieldCell(FieldCell &&other);
    explicit FieldCell(Terrain *terrain);

    bool isEmpty() { return object == nullptr; }
    bool setObject(GameObject *object);
    bool setTerrain(Terrain *terrain);

    void eraseObject();

    [[nodiscard]] GameObject *getObject() const { return object; }
    [[nodiscard]] Terrain *getTerrain() const { return terrain; }

    friend std::ostream& operator<< (std::ostream &stream, const FieldCell &cell);
    FieldCell& operator=(FieldCell &&other);
    FieldCell& operator=(const FieldCell &other);

};

#endif //BATTLEFORHONOUR_FIELDCELL_H
