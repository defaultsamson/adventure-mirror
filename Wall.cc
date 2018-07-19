#include "Wall.h"
#include "Entity.h"
#include "Observer.h"

Wall::Wall(size_t x, size_t y, char icon) : Entity{x, y, icon} {}

void Wall::notify(Observer &o) {
	(void) o; // Unused parameter error
}

