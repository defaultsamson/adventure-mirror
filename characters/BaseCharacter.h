#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "Character.h"
#include "Item.h"

class BaseCharacter: public Character {
protected:
	size_t x, y;
	char icon;
	double hp;
	double maxHp;
	double atk;
	double def;
	int gold = 0;
	size_t floor = 0;
public:
	bool deathCheck() override;
	BaseCharacter(size_t x, size_t y, char icon, double hp, double maxHp, double atk, double def);
	bool hit(Character &other, std::string &output) override;
	double hitPower(Character &other) override;
	bool takeDamage(Character &from, double damage, std::string &output) override;
	void addHP(double hp) override;
	double score() override;
	double getHP() override;
	double getMaxHP() override;
	double getAtk() override;
	double getDef() override;
	void addGold(int value) override;
	int getGold() override;
	size_t getFloor() override;
	void setFloor(size_t f) override;
	size_t getX() override;
	size_t getY() override;
	void setX(size_t x) override;
	void setY(size_t y) override;
	char print() override;
};

#endif
