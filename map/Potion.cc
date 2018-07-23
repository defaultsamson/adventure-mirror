#include "Potion.h"
#include "Item.h"
#include "../DungeonMap.h"

#include <string>

using namespace std;

Potion::Potion(size_t x, size_t y, string name, PotionType type) : Item{x, y, 'P'}, name{name}, type{type} {}

bool Potion::isWalkable() { return false; }
bool Potion::isSpawnable() { return false; }

void Potion::pickup(DungeonMap &map, CharacterDecorator &c, string &output) {
	map.witnessPotion(type);
	output += name;
	(void) c;
}

string Potion::getName() {
	return name;
}

string Potion::to_string() {
	return "Potion " + getName() + "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}