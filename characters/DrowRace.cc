#include "DrowRace.h"
#include "BaseCharacter.h"
#include "Character.h"

DrowRace::DrowRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 150, 150, 25, 15} {}

CharacterType DrowRace::getType() { return CharacterType::Drow; }

