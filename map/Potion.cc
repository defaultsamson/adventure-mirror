#include "Potion.h"
#include "PotionType.h"
#include "Item.h"
#include "../DungeonMap.h"

#include <string>

using namespace std;

Potion::Potion(size_t x, size_t y, PotionType type) : Item{x, y, 'P'}, type{type} {}

bool Potion::isWalkable() { return false; }
bool Potion::isSpawnable() { return false; }

bool Potion::pickup(DungeonMap &map, CharacterDecorator &c, string &output) {
	map.witnessPotion(type);
	output += type.to_string();
	(void) c;
	return true;
}

PotionType Potion::getType() {
	return type;
}

string Potion::to_string() {
	return "Potion " + getType().to_string() + "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}
