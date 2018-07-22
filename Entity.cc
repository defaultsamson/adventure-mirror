#include "Entity.h"
#include "DungeonMap.h"

Entity::Entity() {}

void Entity::move(Direction d) {
    setX(getX() + d.x);
    setY(getY() + d.y);
}

void Entity::moveTick(DungeonMap &map) { (void) map; }
void Entity::tick(DungeonMap &map) { (void) map; }

Entity::~Entity() {}

