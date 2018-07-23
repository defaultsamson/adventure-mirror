#ifndef CHARACTER_H
#define CHARACTER_H

#include "../Entity.h"
#include "CharacterType.h"

class Character: public Entity {
public:
	virtual bool deathCheck() = 0;
	Character();
	virtual bool hit(Character &other, std::string &output) = 0;
	virtual double hitPower(Character &other) = 0;
	virtual bool takeDamage(Character &other, double damage, std::string &output) = 0;
	virtual void addHP(double hp) = 0;
	virtual double score() = 0;
	virtual double getHP() = 0;
	virtual double getMaxHP() = 0;
	virtual double getAtk() = 0;
	virtual double getDef() = 0;
	virtual void addGold(int value) = 0;
	virtual int getGold() = 0;
	virtual CharacterType getType() = 0;
	bool isSpawnable() override;
	bool isWalkable() override;

	virtual std::string to_string();
};

#endif
