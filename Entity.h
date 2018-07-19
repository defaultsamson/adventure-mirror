#ifndef ENTITY_H
#define ENTITY_H

#include "Observer.h"

class Entity: public Observer {
	size_t x, y;
	char icon;
public:
	Entity(size_t x, size_t y, char icon);

	char print() { return icon; }
	virtual ~Entity() = 0;
}

#endif
