#include "Item.h"
#include "Observer.h"

Item::Item(size_t x, size_t y, char icon) : x{x}, y{y}, icon{icon} {}

size_t Item::getX() { return x; }
size_t Item::getY() { return y; }
void Item::setX(size_t x) { this->x = x; }
void Item::setY(size_t y) { this->y = y; }
char Item::print() { return icon; }

void Item::notify(Observer &other) {
	// TODO if player is touching, then apply decorator
	(void) other; // Supresses unused parameter error
}

