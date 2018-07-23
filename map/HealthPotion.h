#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Potion.h"
#include "PotionType.h"
#include "../characters/CharacterDecorator.h"
#include "../DungeonMap.h"
#include <string>

class HealthPotion: public Potion {
	double health;
public:
	HealthPotion(size_t x, size_t y, PotionType type, double health);
	bool pickup(DungeonMap &map, CharacterDecorator &c, std::string &output) override;
};

#endif
