#include "HealthPotion.h"
#include "Potion.h"
#include <string>
#include "../characters/CharacterDecorator.h"
//#include "../DungeonMap.h"

using namespace std;

HealthPotion::HealthPotion(size_t x, size_t y, string name, PotionType type, double health) : Potion{x, y, name, type}, health{health} {}

void HealthPotion::pickup(DungeonMap &map, CharacterDecorator &c, string &output) {
	c.addHP(c.getType() == CharacterType::Drow ? health * 1.5 : health);
	Potion::pickup(map, c, output);
}

