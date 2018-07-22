#ifndef MERCHANT_H
#define MERCHANT_H

#include "Enemy.h"
class Merchant : public Enemy{
public :
	Merchant(size_t x, size_t y);
	void damage(Character &c, int damage) override;
};
#endif
