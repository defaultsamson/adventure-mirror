#include "EffectPotion.h"
#include "Potion.h"
#include "../characters/CharacterDecorator.h"

#include <string>

using namespace std;

EffectPotion::EffectPotion(size_t x, size_t y, string name, PotionType type, CharacterDecorator *effect) : Potion{x, y, name, type}, effect{effect} {}

void EffectPotion::pickup(DungeonMap &map, CharacterDecorator &c, string &output) {
	if (c.getType() == CharacterType::Drow) effect->multiplier = 1.5;
	c.decorate(effect);
	Potion::pickup(map, c, output);
}

