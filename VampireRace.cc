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
		addHP(5);
		return true;
	}
	return false;
}

