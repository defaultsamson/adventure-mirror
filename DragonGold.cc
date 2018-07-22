#include "DragonGold.h"
#include "Gold.h"
#include "Observer.h"

DragonGold::DragonGold(size_t x, size_t y) : Gold{x, y, 6} {}

void DragonGold::notify(Observer &o) {
	(void) o;
	// TODO don't let this gold be picked up if a dragon is alive beside it
}

