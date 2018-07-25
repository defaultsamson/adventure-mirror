#ifndef CHARACTERDECORATOR_H
#define CHARACTERDECORATOR_H

#include "Character.h"

class CharacterDecorator: public Character {
	bool ticked;
protected:
	Character *component;
	size_t activeFloor;
	double multiplier = 1.0;
public:
	CharacterDecorator();
	CharacterDecorator(Character *component);
	bool hit(Character &other, std::string &output) override;
	double hitPower(Character &other) override;
	bool takeDamage(Character &from, double damage, std::string &output) override;
	void decorate(CharacterDecorator *o);
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
	void setActiveFloor(size_t f);
	void setMultiplier(double mult);
	size_t getX() override;
	size_t getY() override;
	void setX(size_t x) override;
	void setY(size_t y) override;
	bool isWalkable() override;
	bool isSpawnable() override;
	char print() override;
	bool deathCheck() override;
	CharacterType getType() override;
	void tick(DungeonMap &map, std::string &output) override;
	void moveTick(DungeonMap &map, std::string &output) override;
	void resetTick();
	std::string to_string() override;
};

#endif
