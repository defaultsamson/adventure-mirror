#include "ElfEnemy.h"

HumanEnemy::HumanEnemy(size_t x, size_t y){
	BaseCharacter(x,y,'E', 140, 140, 30, 10);		
}

//Causes two attacks
ElfEnemy::hit(Character &c){
	//TODO: Causes two attacks
	if (c.type == CharacterType.Drow){
		BaseCharacter.hit(c);
	} else {
		BaseCharacter.hit(c);
		BaseCharacter.hit(c);
	}
}
