#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

#include "Observer.h"
#include "Entity.h"
#include <string>
#include <vector>

using namespace std;

class DungeonMap: public Observer {
	vector<vector<Entity>> grid;
	public:
		DungeonMap(const char* filename);
		void notify(Observer &other) override;
};

#endif