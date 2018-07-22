#ifndef TROLLRACE_H
#define TROLLRACE_H

#include "Character.h"
#include "BaseCharacter.h"
#include "DungeonMap.h"

class TrollRace: public BaseCharacter {
public:
	TrollRace(size_t x, size_t y);
	void tick(DungeonMap &map) override;
	CharacterType getType() override;
};

#endif
