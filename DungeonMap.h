#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

#include "Floor.h"
#include "Character.h"
#include <string>
#include <vector>

class DungeonMap {
	size_t floor = 0;
	vector<Floor*> floors;
	Character *player;
public:
	DungeonMap(const char* filename, Character *player = nullptr);

	size_t getFloor();
	void progressFloor();
	std::vector<Direction> getWalkableDirections(Entity* e); // tiles player can walk on (gold, walkways, doors)
	std::vector<Direction> getSpawnableDirections(Entity* e); // tiles enemies can spawn/walk on

	void movePlayer(Direction d, std::string &output);
	void tick(std::string &output);
	friend std::ostream &operator<<(std::ostream &out, const DungeonMap &m);
};

#endif
