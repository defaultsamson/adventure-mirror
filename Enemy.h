#ifndef ENEMY_H
#define ENEMY_H

#include "CharacterDecorator.h"
#include "BaseCharacter.h"
#include "Observer.h"
class Enemy : public BaseCharacter{
public :
	virtual void notify(Observer &) override;
	virtual ~Enemy() = 0;
};
#endif
