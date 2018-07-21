#include "Potion.h"
#include "Item.h"
#include "CharacterDecorator.h"

#include <string>

Potion::Potion(size_t x, size_t y, string type, CharacterDecorator *effect) : Item{x, y, 'P'}, type{type}, effect{effect} {}

void Potion::pickup(CharacterDecorator *entity) {
	entity->decorate(effect);
	// TODO remove this from the map
}

