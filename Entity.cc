#include "Entity.h"

Entity::Entity(size_t x, size_t y, char icon) : x{x}, y{y}, icon{icon} {}

char Entity::print() { return icon;}
size_t Entity::getX() { return x; }
size_t Entity::getY() { return y; }

Entity::~Entity() {}

