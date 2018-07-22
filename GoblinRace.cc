#include "GoblinRace.h"
#include "BaseCharacter.h"
#include "Character.h"

GoblinRace::GoblinRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 110, 110, 15, 20} {}

bool GoblinRace::hit(Character &other) {
	bool ret = BaseCharacter::hit(other);
	// Note: Keep the other pointer alive in DungeonMap even if the character is dead so that this will run properly
	if (other.deathCheck()) {
		addGold(5);
	}
	return ret;
}

CharacterType GoblinRace::getType() { return CharacterType::Goblin; }

