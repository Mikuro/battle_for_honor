#include "Unit.h"

Unit::Unit(){
    health = 0;
    x = 0;
    y = 0;
}

int Unit::getX() {
    return x;
}
int Unit::getY() {
    return y;
}
int Unit::getHealth() {
    return health;
}

int Unit::getDistance() {
    return distance;
}

Attributes Unit::getStats() {
    return stats;
}

void Unit::setX(int x) {
    this->x = x;
}
void Unit::setY(int y) {
    this->y = y;
}
void Unit::setHealth(int health) {
    this->health = health;
}

void Unit::setDistance(int distance) {
    this->distance = distance;
}

void Unit::setStats(Attributes stats) {
    this->stats = stats;
}
int Unit::getSpeed() {
    return  speed;
}
char Unit::getSymbol() {
    return  symbol;
}
void Unit::setSpeed(int speed) {
    this->speed = speed;
}
void Unit::setSymbol(char symbol) {
    this->symbol = symbol;
}