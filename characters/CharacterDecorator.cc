#include "CharacterDecorator.h"
#include "Character.h"
#include "Item.h"
#include <iostream>

CharacterDecorator::CharacterDecorator() {}
CharacterDecorator::CharacterDecorator(Character *component) : component{component}, activeFloor{component->getFloor()} {}

bool CharacterDecorator::hit(Character &other, std::string &output) {
	return component->hit(other, output);
}

bool CharacterDecorator::takeDamage(Character &from, double damage) {
	return component->takeDamage(from, damage);
}

double CharacterDecorator::hitPower(Character &other) { return component->hitPower(other); }

void CharacterDecorator::decorate(CharacterDecorator *o) {
	o->component = component;
	component = o;
	std::cout << "Decorating" << std::endl;
}

void CharacterDecorator::addHP(double hp) { component->addHP(hp); }
double CharacterDecorator::score() { return component->score(); }
double CharacterDecorator::getHP() { return component->getHP(); }
double CharacterDecorator::getMaxHP() { return component->getMaxHP(); }
double CharacterDecorator::getAtk() { return component->getAtk(); }
double CharacterDecorator::getDef() { return component->getDef(); }
void CharacterDecorator::addGold(int value) { component->addGold(value); }
int CharacterDecorator::getGold() { return component->getGold(); }
size_t CharacterDecorator::getFloor() { return component->getFloor(); }
void CharacterDecorator::setFloor(size_t f) { component->setFloor(f); }
void CharacterDecorator::setActiveFloor(size_t f) { activeFloor = f; }
void CharacterDecorator::setMultiplier(double mult) { multiplier = mult; }
size_t CharacterDecorator::getX() { return component->getX(); }
size_t CharacterDecorator::getY() { return component->getY(); }
void CharacterDecorator::setX(size_t x) { component->setX(x); }
void CharacterDecorator::setY(size_t y) { component->setY(y); }
char CharacterDecorator::print() { return component->print(); }
bool CharacterDecorator::deathCheck() { return component->deathCheck(); }
CharacterType CharacterDecorator::getType() { return component->getType(); }
void CharacterDecorator::tick(DungeonMap &map, std::string &output) {
	// if (!ticked) {
        component->tick(map, output);
		// ticked = true;
	// }
}

void CharacterDecorator::moveTick(DungeonMap &map, std::string &output) { component->moveTick(map, output); }

void CharacterDecorator::resetTick() {
	ticked = false;
}

std::string CharacterDecorator::to_string() {
	return "CharacterDecorator(" + component->to_string() + " on floor " + std::to_string(activeFloor) + ")";
}
