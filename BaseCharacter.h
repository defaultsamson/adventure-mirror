#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "Observer.h"
#include "Character.h"
#include "Item.h"

class BaseCharacter: public Character {
	size_t x, y;
	char icon;
	double hp;
	double maxHp;
	double atk;
	double def;
	int gold = 0;
	int floor = 0;
	CharacterType type;
protected:
	void deathCheck() override;
public:
	BaseCharacter(size_t x, size_t y, char icon, double hp, double maxHp, double atk, double def);
	void hit(Character &other) override;
	double hitPower(Character &other) override;
	void takeDamage(Character &from, double damage) override;
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
	CharacterType getType();
};

#endif
