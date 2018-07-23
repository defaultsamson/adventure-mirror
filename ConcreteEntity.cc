#include "ConcreteEntity.h"

ConcreteEntity::ConcreteEntity(size_t x, size_t y, char icon) : x{x}, y{y}, icon{icon} {}

void ConcreteEntity::setX(size_t x) { this->x = x; }
size_t ConcreteEntity::getX() { return x; }
void ConcreteEntity::setY(size_t y) { this->y = y; }
size_t ConcreteEntity::getY() { return y; }
char ConcreteEntity::print() { return icon; }
void ConcreteEntity::setFloor(size_t floor) { this->floor = floor; }
size_t ConcreteEntity::getFloor() { return floor; }

