#include "WoundDefEffect.h"

double WoundDefEffect::getDef() {
	return component->getDef() - (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

