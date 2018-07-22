#ifndef ENEMY_H
#define ENEMY_H

#include "BaseCharacter.h"
#include "Observer.h"
class Enemy : public BaseCharacter{
public :
	virtual void notify(Observer &ob) override;
        Enemy(size_t x, size_t y, char icon, int hp, int maxHp, int atk, int def);
	virtual ~Enemy() = 0;
};
#endif
