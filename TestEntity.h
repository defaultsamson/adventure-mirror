#ifndef TESTENTITY_H
#define TESTENTITY_H

#include "Entity.h"

class TestEntity: public Entity {

public:
	TestEntity(size_t x, size_t y, char icon) : Entity{x, y, icon}
	~TestEntity() override;
}

#endif
