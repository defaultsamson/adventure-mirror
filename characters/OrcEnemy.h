#ifndef ORCENEMY_H
#define ORCENEMY_H

#include "Character.h"
#include "Enemy.h"
class OrcEnemy : public Enemy{
public :
	//Deal 50% more damage against goblins
	double hitPower(Character &c) override;
	OrcEnemy(size_t x, size_t y);
	CharacterType getType() override;
};
#endif
