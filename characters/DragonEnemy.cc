#include "DragonEnemy.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "../DungeonMap.h"
#include <string>
#include "../map/DragonGold.h"
#include <memory>

using namespace std;

DragonEnemy::DragonEnemy(size_t x, size_t y) : Enemy(x,y,'D', 150, 150, 20, 20) {}

CharacterType DragonEnemy::getType() { return CharacterType::Dragon; }

void DragonEnemy::moveTick(DungeonMap &map, string &output) {
    // dragons don't move
    (void) map;
    (void) output;
}

bool DragonEnemy::canAttack(DungeonMap &map) {
	if (Enemy::canAttack(map)) return true;
	// Otherwise check for surrounding gold

	size_t px = map.getPlayer()->getX();
        size_t py = map.getPlayer()->getY();

	for (size_t x = getX() - 1; x < getX() + 2; ++x) {
		for (size_t y = getY() - 1; y < getY() + 2; ++y) {
			shared_ptr<DragonGold> g = dynamic_pointer_cast<DragonGold>(map.getFloor()->getTop(x, y));
			if (g) {
				size_t dx = px > g->getX() ? px - g->getX() : g->getX() - px;
				size_t dy = py > g->getY() ? py - g->getY() : g->getY() - py;
				if (dx <= 1 && dy <= 1) return true;
			}
		}
	}

	return false;
}

void DragonEnemy::onDeath(DungeonMap &map, std::string &output) {
    (void) map;
	output += " and leaves the Dragon's towering stash unguarded";
}
