#include "CharacterDecorator.h"
#include "Character.h"
#include "Item.h"
#include "Observer.h"

CharacterDecorator::CharacterDecorator() {}
CharacterDecorator::CharacterDecorator(Character *component) : component{component} {}

void CharacterDecorator::hit(Character &other) {
	component->hit(other);
}

void CharacterDecorator::damage(Character &other, int damage) {
	component->damage(other, damage);
}

void CharacterDecorator::decorate(CharacterDecorator *o) {
	o->component = component;
	component = o;
}

int CharacterDecorator::score() { return component->score(); }
int CharacterDecorator::getHP() { return component->getHP(); }
int CharacterDecorator::getMaxHP() { return component->getMaxHP(); }
int CharacterDecorator::getAtk() { return component->getAtk(); }
int CharacterDecorator::getDef() { return component->getDef(); }
void CharacterDecorator::addGold(int value) { addGold(value); }
int CharacterDecorator::getGold() { return component->getGold(); }
int CharacterDecorator::getFloor() { return component->getFloor(); }
size_t CharacterDecorator::getX() { return component->getX(); }
size_t CharacterDecorator::getY() { return component->getY(); }
void CharacterDecorator::setX(size_t x) { component->setX(x); }
void CharacterDecorator::setY(size_t y) { component->setY(y); }
char CharacterDecorator::print() { return component->print(); }

void CharacterDecorator::notify(Observer &o) {
	(void) o;
}

