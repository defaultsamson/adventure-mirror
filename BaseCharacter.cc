#include "Character.h"
#include "BaseCharacter.h"
#include <math.h>

using namespace std;

BaseCharacter::BaseCharacter(size_t x, size_t y, char icon, double hp, double maxHp, double atk, double def) : x{x}, y{y}, icon{icon}, hp{hp}, maxHp{maxHp}, atk{atk}, def{def} {}

// Deal the attack. DO NOT OVERRIDE THIS, instead override hitPower()
bool BaseCharacter::hit(Character &other) {
	return other.takeDamage(*this, hitPower(other));
}

// The default equation for hitpower, from the combat section of the assignment
double BaseCharacter::hitPower(Character &other) {
	return ceil((100.0 / (100.0 + other.getDef())) * getAtk());
}

bool BaseCharacter::takeDamage(Character &from, double damage) {
	(void) from;
	// Class specific defences can override this. By default, take the damage
	hp -= damage;
	deathCheck();
	return true;
}

// This should be checked every time this character takes damage
bool BaseCharacter::deathCheck() {
	if (hp <= 0) {
		// TODO Default death behaviour (e.g. remove from the floor)
		// Expect this to be run twice (E.g. from a GoblinRace)
		return true;
	}
	return false;
}

void BaseCharacter::addHP(double hp) {
	this->hp = max(min(this->hp + hp, getMaxHP()), 0.0);
	deathCheck();
}

double BaseCharacter::score() { return gold; }
double BaseCharacter::getHP() { return hp; }
double BaseCharacter::getMaxHP() { return maxHp; }
double BaseCharacter::getAtk() { return atk; }
double BaseCharacter::getDef() { return def; }
void BaseCharacter::addGold(int value) { gold += value; }
int BaseCharacter::getGold() { return gold; }
int BaseCharacter::getFloor() { return floor; }
size_t BaseCharacter::getX() { return x; }
size_t BaseCharacter::getY() { return y; }
void BaseCharacter::setX(size_t x) { this->x = x; }
void BaseCharacter::setY(size_t y) { this->y = y; }
char BaseCharacter::print() { return icon; }

CharacterType BaseCharacter::getType() { return type;}

