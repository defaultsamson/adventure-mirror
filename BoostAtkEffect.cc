#include "BoostAtkEffect.h"

double BoostAtkEffect::getAtk() {
	return component->getAtk() + (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

