#include "WoundDefEffect.h"

WoundDefEffect::WoundDefEffect() {}

double WoundDefEffect::getDef() {
	return component->getDef() - (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

std::string WoundDefEffect::to_string() {
	return "WoundDefEffect(" + component->to_string() + " on floor " + std::to_string(activeFloor) + ")";
}