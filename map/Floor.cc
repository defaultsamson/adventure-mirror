#include "Floor.h"
#include "../Entity.h"
#include <vector>
#include <iostream>

using namespace std;

Floor::Floor(size_t i, size_t w, size_t h) : i{i}, w{w}, h{h} {
	// initializes the grid with null pointers
	for (size_t x = 0; x < w; ++x) {
		grid.emplace_back(vector<vector<shared_ptr<Entity>>>());
		for (size_t y = 0; y < h; ++y) {
			grid[x].emplace_back(vector<shared_ptr<Entity>>());
		}
	}
}

void Floor::add(shared_ptr<Entity> e) {
	// if (x < w && y < h) grid[x][y] = e;
	e->setFloor(index());
	grid[e->getX()][e->getY()].emplace_back(e);
}

vector<shared_ptr<Entity>> &Floor::get(size_t x, size_t y) {
	return grid[x][y];
}

size_t Floor::spawnX() { return sX; }
size_t Floor::spawnY() { return sY; }
void Floor::setSpawn(size_t x, size_t y) {
	sX = x;
	sY = y;
}

shared_ptr<Entity> Floor::getTop(size_t x, size_t y) {
	if (get(x, y).size() > 0) return get(x, y).back();
	return nullptr;
}

size_t Floor::index() { return i; }
size_t Floor::width() { return w; }
size_t Floor::height() { return h; }

ostream &operator<<(ostream &out, Floor &f) {
	for (size_t y = 0; y < f.height(); ++y) {
		for (size_t x = 0; x < f.width(); ++x) {
			vector<shared_ptr<Entity>> st = f.get(x, y);
			if (st.size() > 0) {
				out << st.back()->print();
			} else {
				out << ' ';
			}
		}
		out << endl;
	}
	return out;
}

