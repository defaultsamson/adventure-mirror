#ifndef DUNGEONMAP_H_
#define DUNGEONMAP_H_

#include "Floor.h"
#include "Character.h"
#include "Chamber.h"
#include "CharacterDecorator.h"
#include "Potion.h"
#include <string>
#include <vector>

class DungeonMap {
	size_t floor = 0;
	vector<Floor*> floors;
	vector<PotionType> potions;
	vector<bool> flags;
	CharacterDecorator *player;
	void populate(Floor* fl, vector<Chamber> c, int cc, Character *player);
public:
	enum MapFlags {
		EnemiesFrozen,
		MerchantsHostile,
		LAST
	};
	DungeonMap(const char* filename, CharacterDecorator *player = nullptr, bool randomEntities = false);

	size_t getFloor();
	void progressFloor();
	std::vector<Direction> getWalkableDirections(Entity* e); // tiles player can walk on (gold, walkways, doors)
	std::vector<Direction> getSpawnableDirections(Entity* e); // tiles enemies can spawn/walk on

	CharacterDecorator *getPlayer();

	void witnessPotion(PotionType t);
	bool seenPotion(PotionType t);

	void move(Entity *e, Direction d);
	void playerMove(Direction d, std::string &output);
	void playerAttack(Direction d, std::string &output);
	void potionPlayer(Direction d, std::string &output);
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
