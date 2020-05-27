#ifndef BATTLEFORHONOUR_GAMEOBJECT_H
#define BATTLEFORHONOUR_GAMEOBJECT_H


#include <ostream>
#include "../Point.h"
#include "../Logs/log.h"

enum class ObjectType{

    UNIT,
    BASE,
    NEUTRAL_OBJECT,

};

class GameObject {

    friend class GameField;

protected:

    ObjectType type;
    Point position;
    bool isOnField = false;

    virtual void print(std::ostream &stream) const = 0;

public:

    explicit GameObject(ObjectType type): type(type){}
    Point getPosition() { return position; }
    ObjectType getType() { return type; }

    friend std::ostream &operator<<(std::ostream &stream, const GameObject &object);
    friend LogProxy& operator<<(LogProxy &logger, GameObject &obj){

        logger << "Object( x: " << obj.position.x << " y: " << obj.position.y << ")";
        return logger;

    }

};


#endif //BATTLEFORHONOUR_GAMEOBJECT_H