#ifndef FLOOR_H
#define FLOOR_H

#include "../Entity.h"
#include <vector>
#include <iostream>

using namespace std;

class Floor {
	size_t i, w, h;
	vector<vector<vector<Entity*>>> grid;
public:
	Floor(size_t i, size_t w, size_t h);
	void add(Entity *e);
	vector<Entity*> &get(size_t x, size_t y);
	Entity *getTop(size_t x, size_t y);
	size_t index();
	size_t width();
	size_t height();

	friend ostream &operator<<(ostream &out, Floor &f);
};

#endif
