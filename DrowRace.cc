#include "DrowRace.h"

DrowRace::DrowRace(size_t x, size_t y) : CharacterDecorator{x, y, '@'} {
	component = new BaseCharacter(125, 25, 25, x, y, '@');
}

