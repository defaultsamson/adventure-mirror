#ifndef DUNGEONMAP_H
#define DUNGEONMAP_H

#include "Observer.h"
#include "Entity.h"
#include <string>
#include <vector>

using namespace std;

class DungeonMap: public Observer {
	vector<vector<Entity&>> grid;
public:
	DungeonMap(char* filename);
	void notify(Observer &other) override;
};

#endif
