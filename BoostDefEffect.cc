#include "BoostDefEffect.h"

double BoostDefEffect::getDef() {
	return component->getDef() + (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

