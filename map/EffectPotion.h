#ifndef EFFECTPOTION_H
#define EFFECTPOTION_H

#include "Potion.h"
#include "CharacterDecorator.h"
#include <string>

using namespace std;

class EffectPotion: public Potion {
	CharacterDecorator *effect;
public:
	EffectPotion(size_t x, size_t y, string type, CharacterDecorator *effect);
	void pickup(CharacterDecorator *entity) override;
};

#endif
