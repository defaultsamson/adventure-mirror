#ifndef TESTENTITY_H
#define TESTENTITY_H

#include "Entity.h"
#include "Observer.h"

class TestEntity: public Entity {

public:
	TestEntity(size_t x, size_t y, char icon);

	void notify(Observer &o) override;

	~TestEntity() override;
};

#endif
