#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

#include "Observer.h"
#include "Floor.h"
#include "Character.h"
#include <string>
#include <vector>

using namespace std;

class DungeonMap: public Observer {
	size_t floor = 0;
	vector<Floor*> floors;
	Character *player;
public:
	DungeonMap(const char* filename, Character *player = nullptr);

	void notify(Observer &other) override;
	size_t getFloor();
	void progressFloor();
	std::vector<Direction> getWalkableDirections(Entity* e); // tiles player can walk on (gold, walkways, doors)
	std::vector<Direction> getSpawnableDirections(Entity* e); // tiles enemies can spawn/walk on

	void movePlayer(Direction d);
	friend ostream &operator<<(ostream &out, const DungeonMap &m);
};

#endif
