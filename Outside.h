#ifndef OUTSIDE_H
#define OUTSIDE_H

#include "Entity.h"
#include "Observer.h"

class Outside: public Entity {
public:
	Outside(size_t x, size_t y);
	void notify(Observer &o) override;
};

#endif
