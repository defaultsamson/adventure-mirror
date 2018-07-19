#include "Pathway.h"
#include "Entity.h"
#include "Observer.h"

Pathway::Pathway(size_t x, size_t y, char icon) : Entity{x, y, icon} {}

void Pathway::notify(Observer &o) {
	(void) o; // Supress unused parameter error
}

