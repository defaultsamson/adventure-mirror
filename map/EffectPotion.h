#ifndef EFFECTPOTION_H
#define EFFECTPOTION_H

#include "Potion.h"
#include "PotionType.h"
#include "../characters/CharacterDecorator.h"
#include "../DungeonMap.h"
#include <string>

class EffectPotion: public Potion {
	CharacterDecorator *effect;
public:
	EffectPotion(size_t x, size_t y, PotionType type, CharacterDecorator *effect);
	void setFloor(size_t f) override;
	void pickup(DungeonMap &map, CharacterDecorator &c, std::string &output) override;
	std::string to_string() override;
};

#endif