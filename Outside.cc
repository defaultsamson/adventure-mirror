#include "Outside.h"
#include "Entity.h"
#include "Observer.h"

Outside::Outside(size_t x, size_t y) : Entity{x, y, ' '} {}

void Outside::notify(Observer &o) {
	(void) o; // Unused parameter error
}

