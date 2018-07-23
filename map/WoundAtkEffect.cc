#include "WoundAtkEffect.h"

WoundAtkEffect::WoundAtkEffect() {}

double WoundAtkEffect::getAtk() {
	return component->getAtk() - (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

std::string WoundAtkEffect::to_string() {
	return "WoundAtkEffect(" + component->to_string() + " on floor " + std::to_string(activeFloor) + ")";
}