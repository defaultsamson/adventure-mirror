#ifndef GOLD_H
#define GOLD_H

#include "Item.h"
#include "../characters/CharacterDecorator.h"
#include <string>
#include "../DungeonMap.h"

class Gold: public Item {
	int value;
public:
	Gold(size_t x, size_t y, int value);
	bool isSpawnable() override;
	bool isWalkable() override;
	bool pickup(DungeonMap &map, CharacterDecorator &c, std::string &output) override;
	int getValue();
};

#endif

