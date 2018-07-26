#ifndef STAIR_H
#define STAIR_H

#include "StaticEntity.h"
#include <string>
#include "../DungeonMap.h"

class Stair: public StaticEntity{
public:
	Stair(size_t x, size_t y);
	void tick(DungeonMap &map, std::string &output) override;
	bool isWalkable() override;
	bool isSpawnable() override;
};

#endif
