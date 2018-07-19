#include "Floor.h"
#include "Entity.h"
#include <vector>
#include <iostream>

using namespace std;

Floor::Floor(size_t w, size_t h) : w{w}, h{h} {
	// initializes the grid with null pointers
	for (size_t x = 0; x < w; ++x) {
		grid.emplace_back(vector<Entity*>());
		for (size_t y = 0; y < h; ++y) {
			grid[x].emplace_back(nullptr);
		}
	}
}

void Floor::add(Entity *e) {
	// if (x < w && y < h) grid[x][y] = e;
	grid[e->getX()][e->getY()] = e;
}

Entity *Floor::get(size_t x, size_t y) {
	if (x < w && y < h) return grid[x][y];
	return nullptr;
}

size_t Floor::width() { return w; }
size_t Floor::height() { return h; }

ostream &operator<<(ostream &out, Floor &f) {
	for (size_t y = 0; y < f.height(); ++y) {
		for (size_t x = 0; x < f.width(); ++x) {
			Entity *e = f.get(x, y);
			if (e) {
				out << e->print();
			} else {
				out << " ";
			}
		}
		out << endl;
	}
	return out;
}

