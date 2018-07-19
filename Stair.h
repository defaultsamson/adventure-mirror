#ifndef STAIR_H
#define STAIR_H

#include "Entity.h"

class Stair : public Entity{
	public :
	Stair(size_t x,y);
	void notify();
}
#endif
