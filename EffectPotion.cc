#include "EffectPotion.h"
#include "Potion.h"
#include "CharacterDecorator.h"

#include <string>

using namespace std;

EffectPotion::EffectPotion(size_t x, size_t y, string name, CharacterDecorator *effect) : Potion{x, y, name}, effect{effect} {}

void EffectPotion::pickup(CharacterDecorator *entity) {
	entity->decorate(effect);
	// TODO remove this from the map
}

