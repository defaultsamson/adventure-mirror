#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

#include "Floor.h"
#include "Character.h"
#include "Chamber.h"
#include "CharacterDecorator.h"
#include <string>
#include <vector>

class DungeonMap {
	size_t floor = 0;
	vector<Floor*> floors;
	Character *player;
	
	void populate(Floor* fl, vector<Chamber> c, int cc, Character *player);
	CharacterDecorator *player;
public:
	DungeonMap(const char* filename, CharacterDecorator *player = nullptr, bool randomEntities = false);

	size_t getFloor();
	void progressFloor();
	std::vector<Direction> getWalkableDirections(Entity* e); // tiles player can walk on (gold, walkways, doors)
	std::vector<Direction> getSpawnableDirections(Entity* e); // tiles enemies can spawn/walk on

	CharacterDecorator *getPlayer();

	void move(Entity *e, Direction d);
	void movePlayer(Direction d, std::string &output);
	void potionPlayer(Direction d, std::string &output);
	void tick(std::string &output);
	friend std::ostream &operator<<(std::ostream &out, const DungeonMap &m);
};
#endif
