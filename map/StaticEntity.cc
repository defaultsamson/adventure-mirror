#include "StaticEntity.h"

StaticEntity::StaticEntity(size_t x, size_t y, char icon) : x{x}, y{y}, icon{icon} {}

size_t StaticEntity::getX() { return x; }
size_t StaticEntity::getY() { return y; }
void StaticEntity::setX(size_t x) { this->x = x; }
void StaticEntity::setY(size_t y) { this->y = y; }
char StaticEntity::print() { return icon; }

