#include "OrcEnemy.h"

OrcEnemy::OrcEnemy(size_t x, size_t y) : Enemy(x,y,'O', 180, 180, 30, 25){}

//Deal more damage against goblins
bool OrcEnemy::hit(Character &c){
	if (c.getType() == CharacterType::Goblin){
		//TODO : Do more damage
		return true;
	} else {
		return BaseCharacter::hit(c);
	}
}
