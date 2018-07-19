#ifndef PATHWAY_H
#define PATHWAY_H

#include "Entity.h"
#include "Observer.h"

class Pathway: public Entity{
public:
	Pathway(size_t x, size_t y);
	void notify(Observer &o);
};
#endif
