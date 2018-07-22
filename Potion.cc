#include "Potion.h"
#include "Item.h"

#include <string>

using namespace std;

Potion::Potion(size_t x, size_t y, string type) : Item{x, y, 'P'}, type{type} {}

bool Potion::isWalkable() { return false; }
bool Potion::isSpawnable() { return false; }

