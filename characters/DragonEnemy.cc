#include "DragonEnemy.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "../DungeonMap.h"
#include <string>

using namespace std;

DragonEnemy::DragonEnemy(size_t x, size_t y) : Enemy(x,y,'D', 150, 150, 20, 20) {}

CharacterType DragonEnemy::getType() { return CharacterType::Dragon; }

void DragonEnemy::moveTick(DungeonMap &map, string &output) {
    // dragons don't move
    (void) map;
    (void) output;
}
