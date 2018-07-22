#include "Entity.h"

Entity::Entity() {}

void Entity::move(Direction d) {
    setX(getX() + d.x);
    setY(getY() + d.y);
}

void Entity::tick() {}

Entity::~Entity() {}

