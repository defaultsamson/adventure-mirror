#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"

enum class CharacterType {
	Shade,
	Drow,
	Vampire,
	Troll,
	Goblin,
	Human,
	Dwarf,
	Elf,
	Orc,
	Merchant,
	Dragon,
	Halfling
};

class Character: public Entity {
public:
	virtual bool deathCheck() = 0;
	Character();
	virtual bool hit(Character &other) = 0;
	virtual double hitPower(Character &other) = 0;
	virtual bool takeDamage(Character &other, double damage) = 0;
	virtual void addHP(double hp) = 0;
	virtual double score() = 0;
	virtual double getHP() = 0;
	virtual double getMaxHP() = 0;
	virtual double getAtk() = 0;
	virtual double getDef() = 0;
	virtual void addGold(int value) = 0;
	virtual int getGold() = 0;
	virtual int getFloor() = 0;
	virtual CharacterType getType() = 0;
	bool isSpawnable() override;
	bool isWalkable() override;
};

#endif
