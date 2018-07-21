#ifndef DRAGONGOLD_H
#define DRAGONGOLD_H

#include "Gold.h"
#include "Observer.h"

class DragonGold: public Gold {
public:
	DragonGold(size_t x, size_t y);
	void notify(Observer &o) override;
};

#endif

