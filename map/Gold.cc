#include "Gold.h"
#include "Item.h"
#include "CharacterDecorator.h"

Gold::Gold(size_t x, size_t y, int value) : Item{x, y, 'G'}, value{value} {}

bool Gold::isSpawnable() { return false; }
bool Gold::isWalkable() { return true; }

void Gold::pickup(CharacterDecorator *entity) {
	entity->addGold(value);
	// TODO remove this from the map
}

