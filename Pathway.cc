#include "Pathway.h"
#include "StaticEntity.h"

Pathway::Pathway(size_t x, size_t y, char icon) : StaticEntity{x, y, icon} {}

bool Pathway::isSpawnable() { return false; }
bool Pathway::isWalkable() { return true; }

