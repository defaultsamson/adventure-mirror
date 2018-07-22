#include "DragonEnemy.h"

DragonEnemy::DragonEnemy(size_t x, size_t y) : Enemy(x,y,'D', 150, 150, 20, 20){}

void DragonEnemy::notify(Observer& obs){
	//Don't move
	(void)obs;
}
