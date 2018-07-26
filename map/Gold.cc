#include "Gold.h"
#include "Item.h"
#include "../characters/CharacterDecorator.h"
#include "../DungeonMap.h"
#include <string>

using namespace std;

Gold::Gold(size_t x, size_t y, int value) : Item{x, y, 'G'}, value{value} {}

bool Gold::isSpawnable() { return false; }
bool Gold::isWalkable() { return true; }

bool Gold::pickup(DungeonMap &map, CharacterDecorator &c, string &output) {
	c.addGold(value);
	(void) map;
	(void) output;
	return true;
}

int Gold::getValue() {
	return value;
}
