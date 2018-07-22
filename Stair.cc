#include "Observer.h"
#include "Stair.h"

Stair::Stair(size_t x, size_t y) : StaticEntity{x, y, '\\'} {}

bool Stair::isSpawnable() { return false; }
bool Stair::isWalkable() { return true; }

void Stair::notify(Observer &o) {
	(void) o;
}

