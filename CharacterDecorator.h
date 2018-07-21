#ifndef CHARACTERDECORATOR_H
#define CHARACTERDECORATOR_H

#include "Character.h"

class CharacterDecorator: public Character {
protected:
	Character *component;
public:
	CharacterDecorator();
	CharacterDecorator(Character *component);
	void hit(Character &other) override;
	void damage(Character &other, int damage) override;
	void decorate(CharacterDecorator *o);
	int score() override;
	int getHP() override;
	int getMaxHP() override;
	int getAtk() override;
	int getDef() override;
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
