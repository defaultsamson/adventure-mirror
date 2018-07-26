#ifndef SHADERACE_H
#define SHADERACE_H

#include "Character.h"
#include "BaseCharacter.h"

class ShadeRace: public BaseCharacter {
public:
	ShadeRace(size_t x, size_t y);
	double score() override;
	CharacterType getType() override;
};

#endif
