#ifndef CHARACTERDECORATOR_H
#define CHARACTERDECORATOR_H

#include "Character.h"

class CharacterDecorator: public Character {
protected:
	Character *component;
	int activeFloor;
public:
	double multiplier = 1.0;

	CharacterDecorator();
	CharacterDecorator(int floor);
	CharacterDecorator(Character *component);
	bool hit(Character &other) override;
	double hitPower(Character &other) override;
	bool takeDamage(Character &from, double damage) override;
	void decorate(CharacterDecorator *o);
	void addHP(double hp) override;
	double score() override;
	double getHP() override;
	double getMaxHP() override;
	double getAtk() override;
	double getDef() override;
	void addGold(int value) override;
	int getGold() override;
	int getFloor() override;
	size_t getX() override;
	size_t getY() override;
	void setX(size_t x) override;
	void setY(size_t y) override;
	char print() override;
	bool deathCheck() override;
	CharacterType getType() override;
	void notify(Observer &o) override;
};

#endif
