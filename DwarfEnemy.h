#ifndef DWARFENEMY_H
#define DWARFENEMY_H

#include "Character.h"
#include "Enemy.h"

class DwarfEnemy : public Enemy{
public :
	DwarfEnemy(size_t x, size_t y);
	CharacterType getType() override;
};

#endif
