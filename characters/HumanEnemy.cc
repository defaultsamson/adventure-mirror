#include "HumanEnemy.h"
#include "Character.h"
#include "BaseCharacter.h"
#include "Enemy.h"

HumanEnemy::HumanEnemy(size_t x, size_t y) : Enemy(x,y,'H', 140, 140, 20, 20) {}

//Drop double gold when killed
bool HumanEnemy::deathCheck(){
	if (BaseCharacter::deathCheck()) {
		// TODO: Drop double normal gold
		// map.floor.add(new Gold(getX(), getY(), 2));
		// map.floor.add(new Gold(getX(), getY(), 2));
		return true;
	}
	return false;
}

CharacterType HumanEnemy::getType() { return CharacterType::Human; }
