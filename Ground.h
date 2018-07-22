#ifndef GROUND_H
#define GROUND_H

#include "StaticEntity.h"
#include "Observer.h"

class Ground: public StaticEntity {
public:
	Ground(size_t x, size_t y);
	bool isSpawnable() override;
	bool isWalkable() override;
	void notify(Observer &o) override;
};

#endif
