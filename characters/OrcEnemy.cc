#include "OrcEnemy.h"
#include "Character.h"

OrcEnemy::OrcEnemy(size_t x, size_t y) : Enemy(x,y,'O', 180, 180, 30, 25){}

//Deal more damage against goblins
double OrcEnemy::hitPower(Character &c){
	return Enemy::hitPower(c) * (c.getType() == CharacterType::Goblin ? 1.5 : 1);
}

CharacterType OrcEnemy::getType() { return CharacterType::Orc; }
