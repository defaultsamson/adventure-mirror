#include "HumanEnemy.h"
#include "Character.h"
#include "BaseCharacter.h"
#include "Enemy.h"
#include "Gold.h"

HumanEnemy::HumanEnemy(size_t x, size_t y) : Enemy(x,y,'H', 140, 140, 20, 20) {}

//Drop double gold when killed
bool HumanEnemy::deathCheck(){
	if (BaseCharacter::deathCheck()) {
		// TODO: Drop double normal gold
		// map.floor.add(new Gold(getX(), getY(), 2));
		// map.floor.add(new Gold(getX(), getY(), 2));
		return true;
	}
	return false;
}

CharacterType HumanEnemy::getType() { return CharacterType::Human; }

void HumanEnemy::onDeath(DungeonMap &map, std::string &output) {
	output += ", causing the Human to violently release the treasure it collected";
	vector <Entity *> &cell = map.getFloor()->get(getX(), getY());
	cell.emplace(cell.end() - 2, new Gold(getX(), getY(), 2)); // create gold below human, which will be deleted
	vector<Direction> spawnable = map.getSpawnableDirections(this);
	if (spawnable.size()) {
		Direction toSpawn = spawnable[rand() % spawnable.size()];
		map.getFloor()->add(new Gold(getX() + toSpawn.x, getY() + toSpawn.y, 2));
	}
	else {
		map.getPlayer()->addGold(2);
		output += ", some of which flies straight into PC's pocket (+2 treasure)";
	}
}