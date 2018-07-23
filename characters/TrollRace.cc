#include "TrollRace.h"
#include "BaseCharacter.h"
#include "Character.h"
#include "../DungeonMap.h"

#include <string>

using namespace std;

TrollRace::TrollRace(size_t x, size_t y) : BaseCharacter{x, y, '@', 120, 120, 25, 15} {}

bool TrollRace::hit(Character &o, std::string &output) {
	if (BaseCharacter::hit(o, output)) {
		addHP(5);
		return true;
	}
	return false;
}

void TrollRace::tick(DungeonMap &map, string &output) {
	(void) map; (void) output;
	addHP(5);
}

CharacterType TrollRace::getType() { return CharacterType::Troll; }

