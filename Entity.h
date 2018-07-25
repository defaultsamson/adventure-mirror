#ifndef ENTITY_H
#define ENTITY_H

#include "Direction.h"
//#include "DungeonMap.h"
#include <string>

class DungeonMap;

class Entity{
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
	virtual void moveTick(DungeonMap &map, std::string &output);
	virtual void tick(DungeonMap &map, std::string &output);
	virtual void setFloor(size_t f) = 0;
	virtual size_t getFloor() = 0;
	virtual ~Entity() = 0;
};

#endif
