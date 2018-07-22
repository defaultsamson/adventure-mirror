#include "HealthPotion.h"
#include "Potion.h"
#include <string>
#include "CharacterDecorator.h"
#include "Character.h"

using namespace std;

HealthPotion::HealthPotion(size_t x, size_t y, string name, double health) : Potion{x, y, name}, health{health} {}

void HealthPotion::pickup(CharacterDecorator *entity) {
	entity->addHP(entity->getType() == CharacterType::Drow ? health * 1.5 : health);
	Potion::pickup(entity);
}

