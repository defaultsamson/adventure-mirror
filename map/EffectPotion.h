#ifndef EFFECTPOTION_H
#define EFFECTPOTION_H

#include "Potion.h"
#include "../characters/CharacterDecorator.h"
//#include "../DungeonMap.h"
#include <string>

class DungeonMap;

class EffectPotion: public Potion {
	CharacterDecorator *effect;
public:
	EffectPotion(size_t x, size_t y, std::string name, PotionType type, CharacterDecorator *effect);
	void pickup(DungeonMap &map, CharacterDecorator &c, std::string &output) override;
};

#endif
