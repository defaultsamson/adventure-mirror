#include "Ground.h"
#include "Entity.h"
#include "Observer.h"

Ground::Ground(size_t x, size_t y) : Entity{x, y, '.'} {}

void Ground::notify(Observer &o) {
	(void) o;
}

