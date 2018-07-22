#ifndef DRAGONENEMY_H
#define DRAGONENEMY_H

#include "Character.h"
#include "Enemy.h"
class DragonEnemy : public Enemy{
public :
	DragonEnemy(size_t x, size_t y);
	void notify(Observer& ob) override;	
	CharacterType getType() override;
};
#endif
