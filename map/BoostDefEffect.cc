#include "BoostDefEffect.h"

BoostDefEffect::BoostDefEffect() {}

double BoostDefEffect::getDef() {
	return component->getDef() + (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

std::string BoostDefEffect::to_string() {
	return "BoostDefEffect(" + component->to_string() + " on floor " + std::to_string(activeFloor) + ")";
}