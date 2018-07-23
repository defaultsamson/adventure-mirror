#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Potion.h"
#include "../characters/CharacterDecorator.h"
//#include "../DungeonMap.h"
#include <string>

class DungeonMap;

class HealthPotion: public Potion {
	double health;
public:
	HealthPotion(size_t x, size_t y, std::string name, PotionType type, double health);
	void pickup(DungeonMap &map, CharacterDecorator &c, std::string &output) override;
};

#endif
