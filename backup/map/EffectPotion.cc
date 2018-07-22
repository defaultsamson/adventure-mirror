#include "EffectPotion.h"
#include "Potion.h"
#include "CharacterDecorator.h"
#include "Character.h"

#include <string>

using namespace std;

EffectPotion::EffectPotion(size_t x, size_t y, string name, CharacterDecorator *effect) : Potion{x, y, name}, effect{effect} {}

void EffectPotion::pickup(CharacterDecorator *entity) {
	if (entity->getType() == CharacterType::Drow) entity->multiplier = 1.5;
	entity->decorate(effect);
	Potion::pickup(entity);
}

