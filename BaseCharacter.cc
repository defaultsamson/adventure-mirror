<<<<<<< HEAD
#include "BaseCharacter.h"
#include "Character.h"
#include "Observer.h"

BaseCharacter::BaseCharacter(size_t x, size_t y, char icon, int hp, int maxHp, int atk, int def) : x{x}, y{y}, icon{icon}, hp{hp}, maxHp{maxHp}, atk{atk}, def{def} {}

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
size_t BaseCharacter::getX() { return x; }
size_t BaseCharacter::getY() { return y; }
void BaseCharacter::setX(size_t x) { this->x = x; }
void BaseCharacter::setY(size_t y) { this->y = y; }
char BaseCharacter::print() { return icon; }

CharacterType BaseCharacter::getType() { return type;}

void BaseCharacter::notify(Observer &o) {
	(void) o;
}

=======
#include "BaseCharacter.h"
#include "Character.h"
#include "Observer.h"

BaseCharacter::BaseCharacter(size_t x, size_t y, char icon, double hp, double maxHp, double atk, double def) : x{x}, y{y}, icon{icon}, hp{hp}, maxHp{maxHp}, atk{atk}, def{def} {}

void BaseCharacter::hit(Character &other) {
	// Class specific attacks can override this. By default, deal the attack
	other.damage(*this, atk);
}

void BaseCharacter::damage(Character &other, double damage) {
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

void BaseCharacter::notify(Observer &o) {
	(void) o;
}

>>>>>>> 7a236811c57b710c82e0c7e2b0717e95c376d351
