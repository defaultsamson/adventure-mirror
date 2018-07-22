#ifndef CHARACTERDECORATOR_H
#define CHARACTERDECORATOR_H

#include "Character.h"

class CharacterDecorator: public Character {
protected:
	Character *component;
	double multiplier = 1.0;
public:
	CharacterDecorator();
	CharacterDecorator(Character *component);
	void hit(Character &other) override;
	void damage(Character &other, double damage) override;
	void decorate(CharacterDecorator *o);
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
	void notify(Observer &o) override;
};

#endif
