#ifndef HALFLINGENEMY_H
#define HALFLINGENEMY_H

#include "Enemy.h"
class HalflingEnemy : public Enemy{
public :
	//50% chance of dodging an attack
	void damage(Character &, int damage) override;
	HalflingEnemy(size_t x, size_t y);
};
#endif
