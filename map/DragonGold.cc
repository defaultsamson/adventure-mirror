#include "DragonGold.h"
#include "Gold.h"
#include "../DungeonMap.h"
#include "../characters/Character.h"
#include "../characters/CharacterDecorator.h"
#include "../characters/CharacterType.h"
#include <string>

using namespace std;

DragonGold::DragonGold(size_t x, size_t y) : Gold{x, y, 6} {}

bool DragonGold::pickup(DungeonMap &map, CharacterDecorator &c, string &output) {
	size_t x = getX(), y = getY();
	for (size_t i = x - 1; i < x + 2; ++i) {
		for (size_t j = y - 1; j < y + 2; ++j) {
			if (i == x && j == y) continue; // ignore current tile
			shared_ptr<Character> e = dynamic_pointer_cast<Character>(map.getFloor()->getTop(i, j));
			if (e && e->getType() == CharacterType::Dragon) return false;
		}
	}
	return Gold::pickup(map, c, output);
}

