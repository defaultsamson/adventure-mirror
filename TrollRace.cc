#include "TrollRace.h"
#include "BaseCharacter.h"
#include "Character.h"

TrollRace::TrollRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 120, 120, 25, 15} {}

void TrollRace::tick() {
	addHP(5);
}

CharacterType TrollRace::getType() { return CharacterType::Troll; }

