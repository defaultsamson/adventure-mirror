#ifndef TROLLRACE_H
#define TROLLRACE_H

#include "Character.h"
#include "BaseCharacter.h"
#include "../DungeonMap.h"
#include <string>

class TrollRace: public BaseCharacter {
public:
	TrollRace(size_t x, size_t y);
	bool hit(Character &o, std::string &output) override;
	void tick(DungeonMap &map, std::string &output) override;
	CharacterType getType() override;
};

#endif
