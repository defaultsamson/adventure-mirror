#include "WoundDefEffect.h"
#include <iostream>

WoundDefEffect::WoundDefEffect() {}

double WoundDefEffect::getDef() {
	return CharacterDecorator::getDef() - (activeFloor == component->getFloor() ? 5 * multiplier : 0);
}

std::string WoundDefEffect::to_string() {
	if (component) {
		std::cout << "toon" << std::endl;
		// our problem here is that component->to_string() is not calling characterdecorator's to_string so it must be a subclass or garbage or something
		std::cout << component->to_string() << "EEE" << std::endl;
		return "WoundDefEffect(" + component->to_string() + " on floor " + std::to_string(activeFloor) + ")";
	}
	return "WoundDefEffect(None on floor " + std::to_string(activeFloor) + ")";
}

