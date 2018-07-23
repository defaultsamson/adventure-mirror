#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "../characters/CharacterDecorator.h"
#include <string>

class DungeonMap;

enum class PotionType { BoostAttack, WoundAttack, BoostDefense, WoundDefense, Health, Poison };

class Potion: public Item {
	std::string name;
	PotionType type;
public:
	Potion(size_t x, size_t y, std::string name, PotionType type);
	bool isWalkable() override;
	bool isSpawnable() override;
	void pickup(DungeonMap &map, CharacterDecorator &c, std::string &output) override;
	std::string getName();
};

#endif
