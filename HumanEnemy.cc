#include "HumanEnemy.h"

HumanEnemy::HumanEnemy(size_t x, size_t y){
	BaseCharacter(x,y,'H', 140, 140, 20, 20);		
}

//Drop double gold when killed
HumanEnemy::deathCheck(){
	//TODO: Drop double gold
}
