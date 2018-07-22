#ifndef DROWRACE_H
#define DROWRACE_H

#include "Character.h"
#include "BaseCharacter.h"

class DrowRace: public BaseCharacter {
public:
	DrowRace(size_t x, size_t y);
	CharacterType getType() override;
};

#endif
