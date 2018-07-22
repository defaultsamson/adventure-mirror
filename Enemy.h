#ifndef ENEMY_H
#define ENEMY_H

#include "BaseCharacter.h"
#include "Character.h"
#include "DungeonMap.h"

class Enemy : public BaseCharacter{
public :
        Enemy(size_t x, size_t y, char icon, double hp, double maxHp, double atk, double def);
	void moveTick(DungeonMap &map);
	bool hit(Character &other) override;
	virtual ~Enemy() = 0;
};
#endif
