#ifndef WOUNDDEFEFFECT_H
#define WOUNDDEFEFFECT_H

#include "CharacterDecorator.h"

class WoundDefEffect: public CharacterDecorator {
public:
	WoundDefEffect();
	double getDef() override;
	std::string to_string() override;
};

#endif

