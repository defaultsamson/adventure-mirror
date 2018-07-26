#ifndef ITEM_H
#define ITEM_H

#include "../Entity.h"
#include "../characters/CharacterDecorator.h"
#include <string>

class DungeonMap;

class Item: public Entity {
	size_t x, y, floor;
	char icon;
public:
	Item(size_t x, size_t y, char icon);
	size_t getX() override;
	size_t getY() override;
	void setX(size_t x) override;
	void setY(size_t y) override;
	void setFloor(size_t f) override;
	size_t getFloor() override;
	char print() override;
	void move(Direction d) override;
	virtual bool pickup(DungeonMap &map, CharacterDecorator &o, std::string &output) = 0;
};

#endif
