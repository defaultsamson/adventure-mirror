#include "WoundDefEffect.h"

WoundDefEffect::WoundDefEffect() {}

double WoundDefEffect::getDef() {
	return CharacterDecorator::getDef() - (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

std::string WoundDefEffect::to_string() {
	return "WoundDefEffect(" + CharacterDecorator::to_string() + " on floor " + std::to_string(activeFloor) + ")";
}
