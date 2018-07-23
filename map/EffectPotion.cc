#include "EffectPotion.h"
#include "Potion.h"
#include "../characters/CharacterDecorator.h"
#include "../DungeonMap.h"

#include <string>
#include <iostream>

using namespace std;

EffectPotion::EffectPotion(size_t x, size_t y, string name, PotionType type, CharacterDecorator *effect) : Potion{x, y, name, type}, effect{effect} {}

void EffectPotion::setFloor(size_t f) {
	Potion::setFloor(f);
	effect->setActiveFloor(f);
}

void EffectPotion::pickup(DungeonMap &map, CharacterDecorator &c, string &output) {
	if (c.getType() == CharacterType::Drow) effect->setMultiplier(1.5);
	c.decorate(effect);
	output += " DANK AF ";
	Potion::pickup(map, c, output);
}

string EffectPotion::to_string() {
	if (effect) {
		return Potion::to_string() + " with effect " + effect->to_string();
	}
	return Potion::to_string();
}