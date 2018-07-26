#ifndef NULLDECORATOR_H
#define NULLDECORATOR_H

#include <string>
#include "CharacterDecorator.h"
#include "Character.h"

class NullDecorator: public CharacterDecorator {
public:
	NullDecorator(std::shared_ptr<Character> component);
	bool hit(Character &o, std::string &output) override;
	double getAtk() override;
	double getDef() override;
	double hitPower(Character &other) override;
};

#endif

