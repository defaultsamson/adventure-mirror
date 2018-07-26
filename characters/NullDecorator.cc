#include "NullDecorator.h"
#include <string>
#include "CharacterDecorator.h"
#include <math.h>

using namespace std;

NullDecorator::NullDecorator(std::shared_ptr<Character> component) : CharacterDecorator{component} {}

bool NullDecorator::hit(Character &other, string &output) {
	bool result = other.takeDamage(*this, hitPower(other), output);
        output += getType().to_string();
        if (result) {
                output += " deals " + std::to_string((int) hitPower(other)) + " damage to " + other.getType().to_string() + ". ";
        }
        else {
                output += " missed! ";
        }
	return result;
}

double NullDecorator::hitPower(Character &other) {
        return ceil((100.0 / (100.0 + other.getDef())) * getAtk());
}

double NullDecorator::getDef() {
	return max(component->getDef(), 0.0);
}

double NullDecorator::getAtk() {
	return max(component->getAtk(), 0.0);
}

