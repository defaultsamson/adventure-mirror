#include "Ground.h"
#include "StaticEntity.h"

Ground::Ground(size_t x, size_t y) : StaticEntity{x, y, '.'} {}

bool Ground::isSpawnable() { return true; }
bool Ground::isWalkable() { return true; }

