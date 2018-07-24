#ifndef MERCHANT_H
#define MERCHANT_H

#include "Character.h"
#include "Enemy.h"
#include <string>
#include "../DungeonMap.h"

class Merchant : public Enemy{
	bool hostile = false;
public:
	Merchant(size_t x, size_t y);
	bool takeDamage(Character &c, double damage, std::string &output) override;
	CharacterType getType() override;
	void tick(DungeonMap &map, std::string &output) override;
	void setHostile(bool value);
	void onDeath(DungeonMap &map, std::string &output) override;
};
#endif
