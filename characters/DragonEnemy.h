#ifndef DRAGONENEMY_H
#define DRAGONENEMY_H

#include "Character.h"
#include "Enemy.h"
class DragonEnemy : public Enemy{
public :
	DragonEnemy(size_t x, size_t y);
	CharacterType getType() override;
	void moveTick(DungeonMap &map, std::string &output) override;
	void onDeath(DungeonMap &map, std::string &output) override;
};
#endif
