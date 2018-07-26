#include "VampireRace.h"
#include "BaseCharacter.h"
#include "Character.h"
#include <math.h>

using namespace std;

VampireRace::VampireRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 50, -1, 25, 25} {}

void VampireRace::addHP(double hp) {
	// The vampire has no maximum HP
	this->hp = max(0.0, this->hp + hp);
}

bool VampireRace::hit(Character &other, std::string &output) {
	// If the hit was successful
	if (BaseCharacter::hit(other, output)) {
		int lifeSteal = other.getType() == CharacterType::Dwarf ? -5 : 5;
		output += getType().to_string();
		if (lifeSteal > 0) {
			output += " heals ";
		}
		else {
			output += " loses ";
		}
		output += std::to_string(lifeSteal) + " HP from a successful attack! ";
		addHP(lifeSteal);
		deathCheck();
		return true;
	}
	return false;
}

CharacterType VampireRace::getType() { return CharacterType::Vampire; }

