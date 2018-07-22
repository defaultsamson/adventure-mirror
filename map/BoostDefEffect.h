#ifndef BOOSTDEFEFFECT_H
#define BOOSTDEFEFFECT_H

#include "CharacterDecorator.h"

class BoostDefEffect: public CharacterDecorator {
public:
	BoostDefEffect();
	double getDef() override;
};

#endif

