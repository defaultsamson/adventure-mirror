#include "OrcEnemy.h"

OrcEnemy::OrcEnemy(size_t x, size_t y){
	BaseCharacter(x,y,'O', 180, 180, 30, 25);		
}

//Deal more damage against goblins
void OrcEnemy::hit(Character &c){
	if (c.type == CharacterType.Goblin){
		//TODO : Do more damage
	} else {
		BaseCharacter.hit(c);
	}
}
