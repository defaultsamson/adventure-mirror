#ifndef HEALTHPOTION_H
#define HEALTHPOTION_H

#include "Potion.h"
#include "CharacterDecorator.h"
#include <string>

using namespace std;

class HealthPotion: public Potion {
	double health;
public:
	HealthPotion(size_t x, size_t y, string name, double health);
	void pickup(CharacterDecorator *entity) override;
};

#endif
