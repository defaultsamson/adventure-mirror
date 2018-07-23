#include "BoostAtkEffect.h"

BoostAtkEffect::BoostAtkEffect() {}

double BoostAtkEffect::getAtk() {
	return component->getAtk() + (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

std::string BoostAtkEffect::to_string() {
	if (component) {
		return "BoostAtkEffect(" + component->to_string() + " on floor " + std::to_string(activeFloor) + ")";
	}
	return "BoostAtkEffect(None on floor " + std::to_string(activeFloor) + ")";
}