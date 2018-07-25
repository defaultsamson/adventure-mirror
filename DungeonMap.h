#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

#include "Floor.h"
#include "Character.h"
#include "Chamber.h"
#include "CharacterDecorator.h"
#include "PotionType.h"
#include <string>
#include <vector>
#include <memory>

class DungeonMap {
	size_t floor = 0;
	vector<shared_ptr<Floor>> floors;
	vector<PotionType> potions;
	vector<bool> flags;
	CharacterDecorator *player;
	void populate(size_t f, vector<Chamber> c);
	bool passTick = false;
	bool won = false;
public:
	enum MapFlags {
		EnemiesFrozen,
		MerchantsHostile,
		LAST
	};
	DungeonMap(const char* filename, CharacterDecorator *player = nullptr, bool randomEntities = false);
	
	shared_ptr<Floor> &getFloor();
	void progressFloor(bool start = false);
	std::vector<Direction> getWalkableDirections(Entity* e); // tiles player can walk on (gold, walkways, doors)
	std::vector<Direction> getSpawnableDirections(Entity* e); // tiles enemies can spawn/walk on
	std::vector<Direction> getSpawnableDirections(Entity* e, size_t f); //overloaded function with a specific floor
	CharacterDecorator *getPlayer();
	void witnessPotion(PotionType t);
	bool wonGame();
	bool seenPotion(PotionType t);
	void move(Entity *e, Direction d);
	bool playerMove(Direction d, std::string &output);
	void playerAttack(Direction d, std::string &output);
	void playerPotion(Direction d, std::string &output);
	void tick(std::string &output);
	friend std::ostream &operator<<(std::ostream &out, const DungeonMap &m);
	bool getFlag(MapFlags f);
	void setFlag(MapFlags f, bool value);
	void toggleFlag(MapFlags f);
	// DEBUG
	std::string validate();
	std::string characterStats();
	std::string itemStats();
};
#endif
