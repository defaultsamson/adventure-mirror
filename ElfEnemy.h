#ifndef ELFENEMY_H
#define ELFENEMY_H

#include "Enemy.h"
class ElfEnemy : public Enemy{
public :
	//Make double attacks
	bool hit(Character &c) override;
	ElfEnemy(size_t x, size_t y);
};
#endif
