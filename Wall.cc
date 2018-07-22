#include "Wall.h"
#include "StaticEntity.h"

Wall::Wall(size_t x, size_t y, char icon) : StaticEntity{x, y, icon} {}

bool Wall::isSpawnable() { return false; }
bool Wall::isWalkable() { return false; }

