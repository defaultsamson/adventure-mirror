#include "Ground.h"
#include "StaticEntity.h"
#include "Observer.h"

Ground::Ground(size_t x, size_t y) : StaticEntity{x, y, '.'} {}

void Ground::notify(Observer &o) {
	(void) o;
}

