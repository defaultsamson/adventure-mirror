#include "Wall.h"
#include "StaticEntity.h"
#include "Observer.h"

Wall::Wall(size_t x, size_t y, char icon) : StaticEntity{x, y, icon} {}

void Wall::notify(Observer &o) {
	(void) o; // Unused parameter error
}

