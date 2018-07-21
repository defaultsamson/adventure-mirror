#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "Observer.h"
#include "Character.h"
#include "Item.h"

class BaseCharacter: public Character {
	int hp = 0;
	int maxHp = 0;
	int atk = 0;
	int def = 0;
	int gold = 0;
	int floor = 0;
protected:
	void deathCheck() override;
public:
	BaseCharacter(size_t x, size_t y, char icon);
	void hit(Character &other) override;
	void damage(Character &other, int damage) override;
	int score() override;
	int getHP() override;
	int getMaxHP() override;
	int getAtk() override;
	int getDef() override;
	int getGold() override;
	int getFloor() override;
	void notify(Observer &o) override;
};

#endif
