#ifndef WALL_H
#define WALL_H

#include "StaticEntity.h"
#include "Observer.h"

class Wall: public StaticEntity {
public:
	Wall(size_t x, size_t y, char icon);
	bool isSpawnable() override;
	bool isWalkable() override;
	void notify(Observer &o) override;
};

#endif
