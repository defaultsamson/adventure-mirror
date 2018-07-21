#ifndef GROUND_H
#define GROUND_H

#include "Entity.h"
#include "Observer.h"

class Ground: public Entity {
public:
	Ground(size_t x, size_t y);
	void notify(Observer &o) override;
};

#endif
