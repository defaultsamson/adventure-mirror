#ifndef STATICENTITY_H
#define STATICENTITY_H

#include "Entity.h"

class StaticEntity: public Entity {
	size_t x, y;
	char icon;
public:
	StaticEntity(size_t x, size_t y, char icon);
	size_t getX() override;
	size_t getY() override;
	void setX(size_t x) override;
	void setY(size_t y) override;
	char print() override;
};

#endif

