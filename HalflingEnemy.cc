#include <stdlib.h>
#include "HalflingEnemy.h"

HalflingEnemy::HalflingEnemy(size_t x, size_t y) : Enemy(x,y,'L', 100, 100, 15, 20){}

//50% chance to dodge
bool HalflingEnemy::takeDamage(Character& c, double damage){
	int roll = (std::rand() % 2);
	if (roll == 0){
		// Dodge
		return false;
	}
	else {
		return BaseCharacter::takeDamage(c, damage);
	}
}
