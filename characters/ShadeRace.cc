#include "ShadeRace.h"
#include "Character.h"
#include "BaseCharacter.h"

ShadeRace::ShadeRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 125, 125, 25, 25} {}

double ShadeRace::score() { return BaseCharacter::score() * 1.5; }

CharacterType ShadeRace::getType() { return CharacterType::Shade; }

