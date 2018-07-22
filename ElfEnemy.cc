#include "ElfEnemy.h"
#include "Character.h"

ElfEnemy::ElfEnemy(size_t x, size_t y) : Enemy(x,y,'E', 140, 140, 30, 10){}

//Causes two attacks
bool ElfEnemy::hit(Character &c){
	//TODO: Causes two attacks
	if (c.getType() == CharacterType::Drow){
		return BaseCharacter::hit(c);
	} else {
		BaseCharacter::hit(c);
		return BaseCharacter::hit(c);
	}
}

CharacterType ElfEnemy::getType() { return CharacterType::Elf; }
