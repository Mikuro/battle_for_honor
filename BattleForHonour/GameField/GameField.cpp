#include "GameField.h"
#include "../Exceptions/StackExceptions.h"


GameField::GameField():
        fieldHeight(0),
        fieldWidth(0),
        field(nullptr)
{}

GameField::GameField(int fieldSize):
        fieldHeight(fieldSize),
        fieldWidth(fieldSize)
{

    field = new FieldCell* [fieldSize];
    for (int i = 0; i < fieldSize; i++){
        field[i] = new FieldCell [fieldSize];
    }
}

GameField::GameField(int fieldHeight, int fieldWidth):
        fieldHeight(fieldHeight),
        fieldWidth(fieldWidth)
{
    field = new FieldCell* [fieldHeight];
    for (int i = 0; i < fieldHeight; i++){
        field[i] = new FieldCell [fieldWidth];
    }
}

void GameField::deleteObject(int x, int y) {

    if (y < 0 || y > fieldHeight || x < 0 || x > fieldWidth){
        throw OutOfRangeExc(x, y);
    }
    field[y][x].eraseObject();

}

bool GameField::addObject(GameObject *object, int x, int y) {

    if (object->isOnField){
        game::log << "[#GameField] Impossible addition of " << *object << " on field" << game::logend;
        throw DoublePlacingExc();
    }

    bool isInBorder = x < fieldWidth && y < fieldHeight && x >= 0 && y >= 0;

    if (isInBorder && field[y][x].isEmpty()){

        field[y][x].setObject(object);
        object->position = Point(x, y);
        object->isOnField = true;

    } else{

        game::log << "[#GameField] Impossible addition of " << *object << " on field" << game::logend;
        throw OutOfRangeExc(x, y);

    }

    return true;
}

void GameField::deleteObject(GameObject *object) {
    deleteObject(object->position.x, object->position.y);
}

void GameField::moveObject(const Point &p1, const Point &p2) {

    if (checkBorder(p1) && checkBorder(p2) && !field[p1.y][p1.x].isEmpty() && field[p2.y][p2.x].isEmpty()){

        field[p2.y][p2.x] = std::move(field[p1.y][p1.x]);
        field[p2.y][p2.x].getObject()->position = p2;
        field[p1.y][p1.x].eraseObject();

    } else{

        game::log << "[#GameField] Impossible to move object from " << p1.x << " " << p1.y << " to " << p2.x << " " << p2.y << game::logend;
        throw ImpossibleMoveExc();

    }

}


void GameField::deleteObject(const Point &point) {
    deleteObject(point.x, point.y);
}


FieldCell *GameField::getCell(const Point &p) const{

    if (p.x < fieldWidth && p.y < fieldHeight)
        return &field[p.y][p.x];
    throw OutOfRangeExc(p.x, p.y);
}

GameField::~GameField() {

    for (int i=0; i<fieldHeight; i++){
        delete []field[i];
    }

    delete []field;

}

void GameField::reset() {

    for (int i=0; i<fieldHeight; i++){
        delete []field[i];
    }

    delete []field;

    field = new FieldCell* [fieldHeight];
    for (int i=0; i<fieldHeight; i++){
        field[i] = new FieldCell [fieldWidth];
    }
}

std::ostream &operator<<(std::ostream &stream, const GameField &field) {

    for (int y = 0; y < field.fieldHeight; y++){
        for (int x = 0; x < field.fieldWidth; x++){
            stream << field.field[y][x];
        }
        stream << std::endl;
    }
    return stream;
}

void GameField::onUnitMove(Unit *unit, Point p) {

    FieldCell *cell = getCell(p);

    if (!cell->isEmpty() && cell->getObject()->getType() == ObjectType::NEUTRAL_OBJECT){

        auto *neutralObject = dynamic_cast<NeutralObject*>(cell->getObject());

        switch (unit->getUnitType()){
            case UnitType::INFANTRY:
                neutralObject->setStrategy(new InfantryStrategy());
                break;
            case UnitType::ARCHER:
                neutralObject->setStrategy(new ArcherStrategy());
                break;
            case UnitType::DRUID:
                neutralObject->setStrategy(new DruidStrategy());
                break;
        }
        (*unit) << neutralObject;
        cell->eraseObject();
    }
    moveObject(unit->getPosition(), p);

}

void GameField::onUnitDestroy(Unit *unit) {
    deleteObject(unit->getPosition());
}

bool GameField::addObject(GameObject *object, Point position) {
    return addObject(object, position.x, position.y);
}

void GameField::onBaseNewUnitCreated(Unit *unit, Point position) {

    bool isPossibleAdd = addObject(unit, position);
    if (isPossibleAdd)
        unit->addObserver(this);

}

bool GameField::addBase(Base *base, Point position) {

    return addBase(base, position.x, position.y);

}

bool GameField::addBase(Base *base, int x, int y) {

    bool isPossibleAdd = addObject(base, x, y);
    if (isPossibleAdd)
        base->addObserver(this);
    return isPossibleAdd;

}

void GameField::onUnitAttack(Unit *unit, Unit *enemy) {

    Terrain *terrain = getCell(unit->getPosition())->getTerrain();
    TerrainProxy terrainProxy(terrain);

    int damage = unit->getWeapon().getDamage() + terrainProxy.getDamageMultiply(unit->getWeapon().getType());
    int def = enemy->getArmor().controlAbsorb() + terrainProxy.getAbsorbMultiply(enemy->getArmor().getArmorType());

    int resDamage = damage - def;

    if (resDamage < 0)
        resDamage = 0;

    enemy->damage(resDamage);
}

bool GameField::checkBorder(const Point &p) const {
    return p.x >= 0 && p.y >= 0 && p.x < fieldWidth && p.y < fieldHeight;
}