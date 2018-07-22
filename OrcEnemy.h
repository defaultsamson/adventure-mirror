#ifndef ORCENEMY_H
#define ORCENEMY_H

#include "Enemy.h"
class OrcEnemy : public Enemy{
public :
	//Deal 50% more damage against goblins
	void hit(Character &c) override;
	OrcEnemy(size_t x, size_t y);
};
#endif
