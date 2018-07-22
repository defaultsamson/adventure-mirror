#ifndef MERCHANT_H
#define MERCHANT_H

#include "Character.h"
#include "Enemy.h"
class Merchant : public Enemy{
public :
	Merchant(size_t x, size_t y);
	bool takeDamage(Character &c, double damage) override;
	CharacterType getType() override;
};
#endif
