#ifndef BELUNGARACE_H
#define BELUNGARACE_H

#include "Character.h"
#include "BaseCharacter.h"

class BelungaRace: public BaseCharacter {
public:
	BelungaRace(size_t x, size_t y);
	CharacterType getType() override;
    double getAtk() override;
};

#endif
