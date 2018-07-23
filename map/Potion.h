#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "PotionType.h"
#include "../characters/CharacterDecorator.h"
#include <string>

class DungeonMap;

class Potion: public Item {
	std::string name;
	PotionType type;
public:
	Potion(size_t x, size_t y, PotionType type);
	bool isWalkable() override;
	bool isSpawnable() override;
	bool pickup(DungeonMap &map, CharacterDecorator &c, std::string &output) override;
	PotionType getType();
	virtual std::string to_string();
};

#endif
