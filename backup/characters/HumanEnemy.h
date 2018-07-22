#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include "Character.h"
#include "Enemy.h"

class HumanEnemy : public Enemy{
public :
	//Drop additional gold when damaged and killed
	bool deathCheck() override;
	HumanEnemy(size_t x, size_t y);
	CharacterType getType() override;
};
#endif
