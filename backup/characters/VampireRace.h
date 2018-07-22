#ifndef VAMPIRERACE_H
#define VAMPIRERACE_H

#include "BaseCharacter.h"
#include "Character.h"

class VampireRace: public BaseCharacter {
public:
	VampireRace(size_t x, size_t y);
	void addHP(double hp) override;
	bool hit(Character &other) override;
	CharacterType getType() override;
};

#endif
