#ifndef BOOSTATKEFFECT_H
#define BOOSTATKEFFECT_H

#include "Character.h"
#include "CharacterDecorator.h"

class BoostAtkEffect: public CharacterDecorator {
public:
	BoostAtkEffect();
	void hit(Character &other) override;
}

#endif

