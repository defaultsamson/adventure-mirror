#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "Observer.h"
#include "Character.h"
#include "Item.h"

class BaseCharacter: public Character {
	int hp;
	int atk;
	int def;
	int maxHp;
	int gold = 0;
	int floor = 0;
protected:
	void deathCheck() override;
public:
	BaseCharacter(size_t x, size_t y, char icon, int hp, int maxHp, int atk, int def);
	void hit(Character &other) override;
	void damage(Character &other, int damage) override;
	int score() override;
	int getHP() override;
	int getMaxHP() override;
	int getAtk() override;
	int getDef() override;
	void addGold(int value) override;
	int getGold() override;
	int getFloor() override;
	void notify(Observer &o) override;
};

#endif
