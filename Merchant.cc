#include "Merchant.h"

Merchant::Merchant(size_t x, size_t y) : Enemy(x,y,'M', 30, 30, 70, 5){}

bool Merchant::takeDamage(Character &c, double damage){
	//TODO Make all merchants hostile
	return BaseCharacter::takeDamage(c, damage);
}
