#include "Wall.h"
#include "StaticEntity.h"
#include "Observer.h"

Wall::Wall(size_t x, size_t y, char icon) : StaticEntity{x, y, icon} {}

bool Wall::isSpawnable() { return false; }
bool Wall::isWalkable() { return false; }

void Wall::notify(Observer &o) {
	(void) o; // Unused parameter error
}

