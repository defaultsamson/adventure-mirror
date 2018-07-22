#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
#include "Observer.h"
#include "CharacterDecorator.h"

class Item: public Entity {
	size_t x, y;
	char icon;
public:
	Item(size_t x, size_t y, char icon);
	size_t getX() override;
	size_t getY() override;
	void setX(size_t x) override;
	void setY(size_t y) override;
	char print() override;
	void notify(Observer &o) override;
	void move(Direction d) override;
	virtual void pickup(CharacterDecorator *o);
};

#endif
