#include "CharacterDecorator.h"
#include "Character.h"
#include "Item.h"
#include "Observer.h"

CharacterDecorator::CharacterDecorator(size_t x, size_t y, char icon) : Character{x, y, icon} {}

void CharacterDecorator::hit(Character &other) {
	component->hit(other);
}

void CharacterDecorator::damage(Character &other, int damage) {
	component->damage(other, damage);
}

void CharacterDecorator::pickup(Item &i) {
	(void) i;
	// TODO pickup logic, wrap the component object
}

int CharacterDecorator::score() { return component->score(); }
int CharacterDecorator::getHP() { return component->getHP(); }
int CharacterDecorator::getMaxHP() { return component->getMaxHP(); }
int CharacterDecorator::getAtk() { return component->getAtk(); }
int CharacterDecorator::getDef() { return component->getDef(); }
int CharacterDecorator::getGold() { return component->getGold(); }
int CharacterDecorator::getFloor() { return component->getFloor(); }

void CharacterDecorator::notify(Observer &o) {
	(void) o;
}

