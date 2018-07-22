#ifndef GOBLINRACE_H
#define GOBLINRACE_H

#include "Character.h"
#include "BaseCharacter.h"

class GoblinRace: public BaseCharacter {
public:
	GoblinRace(size_t x, size_t y);
	CharacterType getType() override;
};

#endif
