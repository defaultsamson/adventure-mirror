#ifndef DUNGEONMAP_H
#define DUNGEONMAP_H

#include "Entity.h"
#include <string>
#include <vector>

class DungeonMap: public Observer {
	vector<vector<Entity&>> grid;
public:
	DungeonMap(string filename);
}

#endif
