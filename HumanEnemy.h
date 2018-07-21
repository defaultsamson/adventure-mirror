#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include "Enemy.h"
class HumanEnemy : public Enemy{
public :
	//Drop additional gold when damaged and killed
	void deathCheck() override;
	HumanEnemy(size_t x, size_t);
};
#endif
