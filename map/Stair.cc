#include "Stair.h"
#include <string>

using namespace std;

Stair::Stair(size_t x, size_t y) : StaticEntity{x, y, '\\'} {}

void Stair::tick(DungeonMap &map, string &output) {
	// The player moved onto the stairs
	if (map.getPlayer()->getX() == getX() && map.getPlayer()->getY() == getY()) {
		map.progressFloor();
	}
	(void) output;
}

bool Stair::isSpawnable() { return false; }
bool Stair::isWalkable() { return true; }

