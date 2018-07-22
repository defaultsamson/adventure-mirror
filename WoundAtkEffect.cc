#include "WoundAtkEffect.h"

double WoundAtkEffect::getAtk() {
	return component->getAtk() - (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

