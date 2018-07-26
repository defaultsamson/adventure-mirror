#ifndef DRAGONGOLD_H
#define DRAGONGOLD_H

#include "Gold.h"

class DragonGold: public Gold {
public:
	DragonGold(size_t x, size_t y);
	bool pickup(DungeonMap &map, CharacterDecorator &c, std::string &output);
};

#endif

