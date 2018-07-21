#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

#include "Observer.h"
#include "Floor.h"
#include <string>
#include <vector>

using namespace std;

class DungeonMap: public Observer {
	size_t floor = 0;
	vector<Floor*> floors;
public:
	DungeonMap(const char* filename);

	void notify(Observer &other) override;
	size_t getFloor();
	void progressFloor();
	std::vector<Direction> getEmptyDirections(Entity* e);

	friend ostream &operator<<(ostream &out, const DungeonMap &m);
};

#endif
