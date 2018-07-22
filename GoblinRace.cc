#include "GoblinRace.h"
#include "BaseCharacter.h"
#include "Character.h"

GoblinRace::GoblinRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 110, 110, 15, 20} {}

CharacterType GoblinRace::getType() { return CharacterType::Goblin; }

