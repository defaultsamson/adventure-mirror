#include "HealthPotion.h"
#include "PotionType.h"
#include "Potion.h"
#include <string>
#include "../characters/CharacterDecorator.h"
#include "../DungeonMap.h"

using namespace std;

HealthPotion::HealthPotion(size_t x, size_t y, PotionType type, double health) : Potion{x, y, type}, health{health} {}

bool HealthPotion::pickup(DungeonMap &map, CharacterDecorator &c, string &output) {
	c.addHP(c.getType() == CharacterType::Drow ? health * 1.5 : health);
	return Potion::pickup(map, c, output);
}

