#include "Merchant.h"

Merchant::Merchant(size_t x, size_t y) : Enemy(x,y,'M', 30, 30, 70, 5){}

void Merchant::damage(Character &c, int damage){
	//TODO Make all merchants hostile
	BaseCharacter::damage(c, damage);
}
