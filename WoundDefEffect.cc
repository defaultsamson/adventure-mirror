#include "WoundDefEffect.h"

WoundDefEffect::WoundDefEffect() {}

double WoundDefEffect::getDef() {
	return component->getDef() - (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

