#include <stdlib.h>
#include "Enemy.h"
#include "Character.h"

using namespace std;

Enemy::Enemy(size_t x, size_t y, char icon, double hp, double maxHp, double atk, double def) : 
	BaseCharacter(x, y, icon, hp, maxHp, atk, def){}

bool Enemy::hit(Character &other) {
	if (rand() % 2) {
		BaseCharacter::hit(other);
		return true;
	}
	return false;
}

Enemy::~Enemy(){}
