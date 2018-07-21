#include "BaseCharacter.h"
#include "Character.h"
#include "Item.h"
#include "Observer.h"

BaseCharacter::BaseCharacter(size_t x, size_t y, char icon) : Character{x, y, icon} {}

void BaseCharacter::hit(Character &other) {
	// Class specific attacks can override this. By default, deal the attack
	other.damage(*this, atk);
}

void BaseCharacter::damage(Character &other, int damage) {
	(void) other;
	// Class specific defences can override this. By default, take the damage
	hp -= damage;
}

// This should be checked every time this character takes damage
void BaseCharacter::deathCheck() {
	if (hp <= 0) {
		// TODO Default death behaviour (e.g. remove from the floor)
	}
}

int BaseCharacter::score() { return gold; }
int BaseCharacter::getHP() { return hp; }
int BaseCharacter::getMaxHP() { return maxHp; }
int BaseCharacter::getAtk() { return atk; }
int BaseCharacter::getDef() { return def; }
void BaseCharacter::addGold(int value) { gold += value; }
int BaseCharacter::getGold() { return gold; }
int BaseCharacter::getFloor() { return floor; }

void BaseCharacter::notify(Observer &o) {
	(void) o;
}

