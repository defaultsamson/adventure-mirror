#ifndef CHAMBER_H
#define CHAMBER_H

#include "Entity.h"
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
struct Coordinate {
	size_t x,y;
}

class Chamber {
	Vector<Coordinate> tiles;
	bool hasStair;
	int size;
public :
	Chamber();
	void add(size_t x, y);
	bool isEmpty();
	Entity* spawnObject(char c);
	void Shuffle(std::random_device rd);
};
#endif
