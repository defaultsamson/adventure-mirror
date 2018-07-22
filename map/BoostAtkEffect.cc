#include "BoostAtkEffect.h"

BoostAtkEffect::BoostAtkEffect() {}

double BoostAtkEffect::getAtk() {
	return component->getAtk() + (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

