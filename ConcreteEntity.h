#ifndef CONCRETEENTITY_H
#define CONCRETEENTITY_H

#include <stdio.h>

class ConcreteEntity {
	size_t x;
	size_t y;
	size_t floor;
	char icon;
public:
	ConcreteEntity(size_t x, size_t y, char icon);

	size_t getX();
        size_t getY();
        void setX(size_t x);
        void setY(size_t y);
        char print();
        void setFloor(size_t f);
        size_t getFloor();
};

#endif

