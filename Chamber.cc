#include "Chamber.h"
#include "Stair.h"
#include "Potion.h"
#include "HealthPotion.h"
#include "EffectPotion.h"
#include "BoostAtkEffect.h"
#include "BoostDefEffect.h"
#include "WoundAtkEffect.h"
#include "WoundDefEffect.h"
#include "Gold.h"
#include "DragonGold.h"
#include "Stair.h"
#include "HumanEnemy.h"
#include "ElfEnemy.h"
#include "DwarfEnemy.h"
#include "OrcEnemy.h"
#include "HalflingEnemy.h"
#include "Merchant.h"
#include "DragonEnemy.h"

Chamber::Chamber() : size{0}, hasStair{false}{}

void Chamber::add(size_t x, size_t y){
	Coordinate c = {x,y};
	tiles.emplace_back(c);
	++size;	
}

void Chamber::remove(size_t x, size_t y){
	for (int i = 0; i < size; ++i){
		Coordinate c = tiles[i];
		if (c.x == x && c.y == y){
			tiles.erase(tiles.begin() + i);
		}
	}
	--size;
}

bool Chamber::isEmpty(){
	if (size > 0){
		return false;
	} else {
		return true;
	}
}

void Chamber::shuffle(std::default_random_engine &eng){
	std::shuffle(tiles.begin(), tiles.end(), eng);
}

Entity* Chamber::spawnObject(char c){
	//Return the entity spawned at the last position in the vector
	Coordinate pos = tiles.back();
	size_t x = pos.x;
	size_t y = pos.y;
	tiles.pop_back();
	--size;
	switch(c) {
		case '\\' : //create stair
			return new Stair(x,y);
		case '0': // restore health
			return new HealthPotion(x, y, PotionType::Health, 10);
		case '1': // boost attack
			return new EffectPotion(x, y, PotionType::BoostAttack, new BoostAtkEffect());
		case '2': // boost defense
			return new EffectPotion(x, y, PotionType::BoostDefense, new BoostDefEffect());
		case '3': // poison health
			return new HealthPotion(x, y, PotionType::Poison, -10);
		case '4': // wound attack
			return new EffectPotion(x, y, PotionType::WoundAttack, new WoundAtkEffect());
		case '5': // wound defense
			return new EffectPotion(x, y, PotionType::WoundDefense, new WoundDefEffect());
		case '6': // normal gold pile
			return new Gold(x, y, 2);
		case '7': // small hoard
			return new Gold(x, y, 1);
		case '8': // merchant hoard
			return new Gold(x, y, 4);
		case '9': // dragon hoard
			return new DragonGold(x, y);
		case 'H': //human enemy
			return new HumanEnemy(x,y);
		case 'W': //dwarf enemy
			return new DwarfEnemy(x,y);
		case 'E': //elf enemy
			return new ElfEnemy(x,y);
		case 'O': //orc enemy
			return new OrcEnemy(x,y);
		case 'L': //halfling enemy
			return new HalflingEnemy(x,y);
		case 'M': //merchant
			return new Merchant(x,y);
		case 'D': //dragon enemy
			return new DragonEnemy(x,y);
	}
	return nullptr;
}
