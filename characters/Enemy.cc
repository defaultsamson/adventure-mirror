#include <stdlib.h>
#include "Enemy.h"
#include "Character.h"
#include "../DungeonMap.h"
#include "Direction.h"
#include <math.h>
#include <string>

using namespace std;

Enemy::Enemy(size_t x, size_t y, char icon, double hp, double maxHp, double atk, double def) : BaseCharacter(x, y, icon, hp, maxHp, atk, def){}

bool Enemy::canAttack(DungeonMap &map) {
	size_t px = map.getPlayer()->getX();
	size_t py = map.getPlayer()->getY();
	size_t dx = px > getX() ? px - getX() : getX() - px;
	size_t dy = py > getY() ? py - getY() : getY() - py;
	return dx <= 1 && dy <= 1;
}

void Enemy::moveTick(DungeonMap &map, string &output) {
	if (moved || canAttack(map)) return;
	(void) output;
	vector<Direction> dirs = map.getSpawnableDirections(this);
	// If the enemy is not stuck in a location
	if (dirs.size() > 0) {
		// Moves in one of the random available directions
		map.move(this, dirs[rand() % dirs.size()]);
	}
	moved = true;
}

void Enemy::tick(DungeonMap &map, string &output) { 
	if (moved) {
		// Enemy moved
		moved = false;
	} else if (canAttack(map)) {
		// Enemy didn't move and can still attack
		hit(*map.getPlayer(), output);
	}
	(void) output;
}

bool Enemy::hit(Character &other, string &output) {
	if (rand() % 2) {
		BaseCharacter::hit(other, output);
		return true;
	}
	output += getType().to_string() + " missed! ";
	return false;
}

Enemy::~Enemy(){}
