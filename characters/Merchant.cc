#include "Merchant.h"

Merchant::Merchant(size_t x, size_t y) : Enemy(x,y,'M', 30, 30, 70, 5){}

bool Merchant::takeDamage(Character &c, double damage){
	//TODO Make all merchants hostile
	return BaseCharacter::takeDamage(c, damage);
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

