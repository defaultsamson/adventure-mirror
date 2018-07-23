#include "Merchant.h"

Merchant::Merchant(size_t x, size_t y) : Enemy(x,y,'M', 30, 30, 70, 5){}

bool Merchant::takeDamage(Character &c, double damage, string &output){
	// TODO set merchants to be hostile
	return Enemy::takeDamage(c, damage, output);
}

void Merchant::tick(DungeonMap &map, string &output) { 
	setHostile(map.getFlag(map.MapFlags::MerchantsHostile));
	if (moved || hostile) {
		Enemy::tick(map, output);
	}
	else if (canAttack(map)) {
		output += "PC makes small talk with the Merchant. ";
	}
}

void Merchant::setHostile(bool value) {
	hostile = value;
}

CharacterType Merchant::getType() { return CharacterType::Merchant; }

