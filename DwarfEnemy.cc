#include "DwarfEnemy.h"

DwarfEnemy::DwarfEnemy(size_t x, size_t y) : Enemy(x,y,'W', 100, 100, 20, 30){}

CharacterType DwarfEnemy::getType() { return CharacterType::Dwarf; }

