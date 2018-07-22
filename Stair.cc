#include "Observer.h"
#include "Stair.h"

Stair::Stair(size_t x, size_t y) : StaticEntity{x, y, '\\'}

void Stair::notify(Observer &o) {
	(void) o;
}

