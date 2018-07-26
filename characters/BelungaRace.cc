#include "BelungaRace.h"
#include "BaseCharacter.h"
#include "Character.h"

BelungaRace::BelungaRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 150, 150, 10, 25} {}

CharacterType BelungaRace::getType() { return CharacterType::Belunga; }

double BelungaRace::getAtk() {
    return BaseCharacter::getAtk() + (getMaxHP() - getHP());
}

