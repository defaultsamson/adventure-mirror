#include "TestEntity.h"
#include "Entity.h"
#include "Observer.h"

TestEntity::TestEntity(size_t x, size_t y, char icon) : Entity{x, y, icon} {}

void TestEntity::notify(Observer &o) {
	(void) o; // Used to supress unused variable error
}

TestEntity::~TestEntity() {}

