#ifndef BASECHARACTER_H
#define BASECHARACTER_H

#include "Observer.h"
#include "Character.h"
#include "Item.h"

class BaseCharacter: public Character {
	size_t x, y;
	char icon;
	int hp;
	int maxHp;
	int atk;
	int def;
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
	size_t getX() override;
	size_t getY() override;
	void setX(size_t x) override;
	void setY(size_t y) override;
        char print() override;
	void notify(Observer &o) override;
	CharacterType getType();
};

#endif
