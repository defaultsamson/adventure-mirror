#include "Character.h"

Character::Character() {} 

bool Character::isSpawnable() { return false; }
bool Character::isWalkable() { return false; }

std::string Character::to_string() {
	std::string output;
	output += std::string(1, print()) + " " + getType().to_string() + "(" + std::to_string(getX());
	output += ", " + std::to_string(getY()) + ") HP: " + std::to_string(getHP()) + "/" + std::to_string(getMaxHP());
	output += " Atk: " + std::to_string(getAtk()) + " Def: " + std::to_string(getDef());
	return output;
}