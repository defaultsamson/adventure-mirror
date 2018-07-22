#ifndef STAIR_H
#define STAIR_H

#include "Observer.h"
#include "StaticEntity.h"

class Stair: public StaticEntity{
public:
	Stair(size_t x, size_t y);
	void notify(Observer &o) override;
};

#endif
