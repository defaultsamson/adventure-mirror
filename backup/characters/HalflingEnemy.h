#ifndef HALFLINGENEMY_H
#define HALFLINGENEMY_H

#include "Character.h"
#include "Enemy.h"
class HalflingEnemy : public Enemy{
public :
	//50% chance of dodging an attack
	bool takeDamage(Character &from, double damage) override;
	HalflingEnemy(size_t x, size_t y);
	CharacterType getType() override;
};
#endif
