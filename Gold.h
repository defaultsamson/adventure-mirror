#ifndef GOLD_H
#define GOLD_H

#include "Item.h"
#include "CharacterDecorator.h"

class Gold: public Item {
	int value;
public:
	Gold(size_t x, size_t y, int value);
	void pickup(CharacterDecorator *entity) override;
}

#endif

