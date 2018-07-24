#ifndef ENEMY_H
#define ENEMY_H

#include "BaseCharacter.h"
#include "Character.h"
#include "../DungeonMap.h"
#include <string>

class Enemy : public BaseCharacter{
protected:
	bool moved = false;
public:
	Enemy(size_t x, size_t y, char icon, double hp, double maxHp, double atk, double def);
	void moveTick(DungeonMap &map, std::string &output) override;
	void tick(DungeonMap &map, std::string &output) override;
	bool canAttack(DungeonMap &map);
	bool hit(Character &other, std::string &output) override;
	virtual void onDeath(DungeonMap &map, std::string &output);
	virtual ~Enemy() = 0;
};

#endif
