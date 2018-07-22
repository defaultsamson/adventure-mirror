#ifndef WOUNDATKEFFECT_H
#define WOUNDATKEFFECT_H

#include "CharacterDecorator.h"

class WoundAtkEffect: public CharacterDecorator {
public:
	WoundAtkEffect();
	double getAtk() override;
};

#endif

