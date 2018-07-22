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

bool VampireRace::hit(Character &other) {
	// If the hit was successful
	if (BaseCharacter::hit(other)) {
		addHP(other.getType() == CharacterType::Dwarf ? -5 : 5);
		deathCheck();
		return true;
	}
	return false;
}

CharacterType VampireRace::getType() { return CharacterType::Vampire; }

