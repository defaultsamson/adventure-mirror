#ifndef ELFENEMY_H
#define ELFENEMY_H

#include "Character.h"
#include "Enemy.h"
class ElfEnemy : public Enemy{
public :
	//Make double attacks
	bool hit(Character &c) override;
	ElfEnemy(size_t x, size_t y);
	CharacterType getType() override;
};
#endif
