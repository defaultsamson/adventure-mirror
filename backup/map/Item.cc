#include "Item.h"
#include "CharacterDecorator.h"

Item::Item(size_t x, size_t y, char icon) : x{x}, y{y}, icon{icon} {}

size_t Item::getX() { return x; }
size_t Item::getY() { return y; }
void Item::setX(size_t x) { this->x = x; }
void Item::setY(size_t y) { this->y = y; }
char Item::print() { return icon; }

void Item::move(Direction d) {
	(void) d; // intentional, items do not move
}

void Item::pickup(CharacterDecorator *entity) {
	// TODO remove this from the map
	(void) entity;
}

