#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"
#include "Observer.h"
#include "CharacterDecorator.h"

class Item: public Entity {
public:
	Item(size_t x, size_t y, char icon);
	void notify(Observer &o) override;
	virtual void pickup(CharacterDecorator *o) = 0;
};

#endif
