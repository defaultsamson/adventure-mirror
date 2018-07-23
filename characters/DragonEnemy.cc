#include "DragonEnemy.h"

DragonEnemy::DragonEnemy(size_t x, size_t y) : Enemy(x,y,'D', 150, 150, 20, 20){}

CharacterType DragonEnemy::getType() { return CharacterType::Dragon; }

void DragonEnemy::moveTick(DungeonMap &map, std::string &output) {
    // dragons don't move
    (void) map;
    (void) output;
}