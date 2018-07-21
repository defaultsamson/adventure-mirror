#include "Item.h"
#include "Observer.h"
#include "Entity.h"

Item::Item(size_t x, size_t y, char icon) : Entity{x, y, icon} {}

void Item::notify(Observer &other) {
	// TODO if player is touching, then apply decorator
	(void) other; // Supresses unused parameter error
}

