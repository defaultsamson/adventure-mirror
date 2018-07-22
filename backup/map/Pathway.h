#ifndef PATHWAY_H
#define PATHWAY_H

#include "StaticEntity.h"

class Pathway: public StaticEntity{
public:
	Pathway(size_t x, size_t y, char icon);
	bool isWalkable() override;
	bool isSpawnable() override;
};
#endif
