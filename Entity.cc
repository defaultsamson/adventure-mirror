#include "Entity.h"
#include "DungeonMap.h"
#include <iostream>

using namespace std;

Entity::Entity() {}

void Entity::move(Direction d) {
    setX(getX() + d.x);
    setY(getY() + d.y);
}

void Entity::moveTick(DungeonMap &map, std::string &output) { (void) map; (void) output; }
void Entity::tick(DungeonMap &map, std::string &output) { (void) map; (void) output; }

Entity::~Entity() {}

