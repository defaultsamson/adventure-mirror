#include "GoblinRace.h"
#include "BaseCharacter.h"
#include "Character.h"

GoblinRace::GoblinRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 110, 110, 15, 20} {}

bool GoblinRace::hit(Character &other, std::string &output) {
	bool ret = BaseCharacter::hit(other, output);
	// Note: Keep the other pointer alive in DungeonMap even if the character is dead so that this will run properly
	if (other.deathCheck()) {
		addGold(5);
		output += "Goblin steals an extra 5 treasure from the " + other.getType().to_string() + "'s body! ";
	}
	return ret;
}

CharacterType GoblinRace::getType() { return CharacterType::Goblin; }

