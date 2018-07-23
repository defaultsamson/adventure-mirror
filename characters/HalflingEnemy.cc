#include <stdlib.h>
#include "HalflingEnemy.h"
#include "Character.h"
#include <string>
#include "Enemy.h"

using namespace std;

HalflingEnemy::HalflingEnemy(size_t x, size_t y) : Enemy(x,y,'L', 100, 100, 15, 20){}

//50% chance to dodge
bool HalflingEnemy::takeDamage(Character& c, double damage, string &output){
	if (rand() % 2) return Enemy::takeDamage(c, damage, output);
	return false;
}

CharacterType HalflingEnemy::getType() { return CharacterType::Halfling; }

