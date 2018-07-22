#include "ElfEnemy.h"

ElfEnemy::ElfEnemy(size_t x, size_t y) : Enemy(x,y,'E', 140, 140, 30, 10){}

//Causes two attacks
void ElfEnemy::hit(Character &c){
	//TODO: Causes two attacks
	if (c.getType() == CharacterType::Drow){
		BaseCharacter::hit(c);
	} else {
		BaseCharacter::hit(c);
		BaseCharacter::hit(c);
	}
}
