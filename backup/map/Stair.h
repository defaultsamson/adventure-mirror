#ifndef STAIR_H
#define STAIR_H

#include "StaticEntity.h"

class Stair: public StaticEntity{
public:
	Stair(size_t x, size_t y);
	bool isWalkable() override;
	bool isSpawnable() override;
};

#endif
