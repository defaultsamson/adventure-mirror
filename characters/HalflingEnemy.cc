#include <stdlib.h>
#include "HalflingEnemy.h"
#include "Character.h"

using namespace std;

HalflingEnemy::HalflingEnemy(size_t x, size_t y) : Enemy(x,y,'L', 100, 100, 15, 20){}

//50% chance to dodge
bool HalflingEnemy::takeDamage(Character& c, double damage){
	if (rand() % 2) {
		// Dodge
		return false;
	}
	else {
		return BaseCharacter::takeDamage(c, damage);
	}
}

CharacterType HalflingEnemy::getType() { return CharacterType::Halfling; }

