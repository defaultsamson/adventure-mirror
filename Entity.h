#ifndef ENTITY_H
#define ENTITY_H

#include "Observer.h"
#include "Direction.h"

class Entity: public Observer {
public:
	Entity();

	virtual size_t getX() = 0;
	virtual size_t getY() = 0;
	virtual void setX(size_t x) = 0;
	virtual void setY(size_t y) = 0;
	virtual char print() = 0;
	virtual bool isSpawnable() = 0;
	virtual bool isWalkable() = 0;
	virtual void move(Direction d);
	virtual ~Entity() = 0;
};

#endif
