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
#include "CharacterDecorator.h"

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

shared_ptr<Entity> Chamber::spawnObject(char c){
	//Return the entity spawned at the last position in the vector
	Coordinate pos = tiles.back();
	size_t x = pos.x;
	size_t y = pos.y;
	tiles.pop_back();
	--size;
	switch(c) {
		case '\\' : //create stair
			return shared_ptr<Entity>(new Stair(x,y));
		case '0': // restore health
			return shared_ptr<Entity>(new HealthPotion(x, y, PotionType::Health, 10));
		case '1': // boost attack
			return shared_ptr<Entity>(new EffectPotion(x, y, PotionType::BoostAttack, shared_ptr<CharacterDecorator>(new BoostAtkEffect())));
		case '2': // boost defense
			return shared_ptr<Entity>(new EffectPotion(x, y, PotionType::BoostDefense, shared_ptr<CharacterDecorator>(new BoostDefEffect())));
		case '3': // poison health
			return shared_ptr<Entity>(new HealthPotion(x, y, PotionType::Poison, -10));
		case '4': // wound attack
			return shared_ptr<Entity>(new EffectPotion(x, y, PotionType::WoundAttack, shared_ptr<CharacterDecorator>(new WoundAtkEffect())));
		case '5': // wound defense
			return shared_ptr<Entity>(new EffectPotion(x, y, PotionType::WoundDefense, shared_ptr<CharacterDecorator>(new WoundDefEffect())));
		case '6': // normal gold pile
			return shared_ptr<Entity>(new Gold(x, y, 2));
		case '7': // small hoard
			return shared_ptr<Entity>(new Gold(x, y, 1));
		case '8': // merchant hoard
			return shared_ptr<Entity>(new Gold(x, y, 4));
		case '9': // dragon hoard
			return shared_ptr<Entity>(new DragonGold(x, y));
		case 'H': //human enemy
			return shared_ptr<Entity>(new HumanEnemy(x,y));
		case 'W': //dwarf enemy
			return shared_ptr<Entity>(new DwarfEnemy(x,y));
		case 'E': //elf enemy
			return shared_ptr<Entity>(new ElfEnemy(x,y));
		case 'O': //orc enemy
			return shared_ptr<Entity>(new OrcEnemy(x,y));
		case 'L': //halfling enemy
			return shared_ptr<Entity>(new HalflingEnemy(x,y));
		case 'M': //merchant
			return shared_ptr<Entity>(new Merchant(x,y));
		case 'D': //dragon enemy
			return shared_ptr<Entity>(new DragonEnemy(x,y));
	}
	return nullptr;
}
