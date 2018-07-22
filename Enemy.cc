#include "Enemy.h"
Enemy::Enemy(size_t x, size_t y, char icon, int hp, int maxHp, int atk, int def) : 
	BaseCharacter(x, y, icon, hp, maxHp, atk, def){}

void Enemy::notify(Observer& obs){
	//TODO :: Add movement for enemies
        (void)obs;
}

Enemy::~Enemy(){}
