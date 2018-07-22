#ifndef TROLLRACE_H
#define TROLLRACE_H

#include "BaseCharacter.h"

class TrollRace: public BaseCharacter {
public:
	TrollRace(size_t x, size_t y);
	void tick() override;
};

#endif
