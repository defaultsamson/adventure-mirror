#ifndef CHAMBER_H
#define CHAMBER_H

#include "Entity.h"
#include <vector>
#include <memory>

struct Coordinate {
	size_t x,y;
};

class Chamber {
	std::vector<Coordinate> tiles;
	int size;
	bool hasStair;
public :
	Chamber();
	void add(size_t x, size_t y);
	void remove(size_t x, size_t y);
	bool isEmpty();
	std::shared_ptr<Entity> spawnObject(char c);
	void shuffle();
};
#endif
