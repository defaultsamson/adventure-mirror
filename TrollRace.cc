#include "TrollRace.h"
#include "BaseCharacter.h"

TrollRace::TrollRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 120, 120, 25, 15} {}

void TrollRace::tick() {
	addHP(5);
}

