#include "Pathway.h"
#include "StaticEntity.h"
#include "Observer.h"

Pathway::Pathway(size_t x, size_t y, char icon) : StaticEntity{x, y, icon} {}

bool Pathway::isSpawnable() { return false; }
bool Pathway::isWalkable() { return true; }

void Pathway::notify(Observer &o) {
	(void) o; // Supress unused parameter error
}

