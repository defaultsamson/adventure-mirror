#ifndef CHAMBER_H
#define CHAMBER_H

#include "Entity.h"
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
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
	bool isEmpty();
	Entity* spawnObject(char c);
	void Shuffle();
};
#endif
