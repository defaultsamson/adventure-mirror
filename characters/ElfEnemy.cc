#include "ElfEnemy.h"
#include "Character.h"

ElfEnemy::ElfEnemy(size_t x, size_t y) : Enemy(x,y,'E', 140, 140, 30, 10){}

//Causes two attacks
bool ElfEnemy::hit(Character &c, std::string &output){
	//TODO: Causes two attacks
	if (c.getType() == CharacterType::Drow){
		return Enemy::hit(c, output);
	} else {
		Enemy::hit(c, output);
		return Enemy::hit(c, output);
	}
}

CharacterType ElfEnemy::getType() { return CharacterType::Elf; }
