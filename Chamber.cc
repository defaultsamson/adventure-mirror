#include "Chamber.h"
Chamber::Chamber() : size{0}, hasStair{false}{}

void Chamber::add(size_t x, y){
	Coordinate c = {x,y}
	tiles.emplace_back(c);
	++size;	
}

bool Chamber::isEmpty(){
	if (size > 0){
		return false;
	} else {
		return true;
	}
}

void Chamber::Shuffle(){
	std::random_shuffle(tiles.begin(), tiles.end());
}

Entity* Chamber::spawnObject(char c){
	//Return the entity spawned at the last position in the vector
	Coordinate pos = tiles.back();
	size_t x = pos.x;
	size_t y = pos.y;
	tiles.pop_back();
	switch(c) {
		case '0': // restore health
			return new HealthPotion(x, y, "Restore Health", 5);
			break;
		case '1': // boost attack
			return new EffectPotion(x, y, "Boost Attack", new BoostAtkEffect());
			break;
		case '2': // boost defense
			return new EffectPotion(x, y, "Boost Defences", new BoostDefEffect());
			break;
		case '3': // poison health
			return new HealthPotion(x, y, "Poison Health", -5);
			break;
		case '4': // wound attack
			return new EffectPotion(x, y, "Wound Attack", new WoundAtkEffect());
			break;
		case '5': // wound defense
			return new EffectPotion(x, y, "Wound Defense", new WoundDefEffect());
			break;
		case '6': // normal gold pile
			return new Gold(x, y, 2);
			break;
		case '7': // small hoard
			return new Gold(x, y, 1);
			break;
		case '8': // merchant hoard
			return new Gold(x, y, 4);
			break;
		case '9': // dragon hoard
			return new DragonGold(x, y);
			break;
		case 'H': //human enemy
			return new HumanEnemy(x,y);
			break;
		case 'W': //dwarf enemy
			return new DwarfEnemy(x,y);
			break;
		case 'E': //elf enemy
			return new ElfEnemy(x,y);
			break;
		case 'O': //orc enemy
			return new OrcEnemy(x,y);
			break;
		case 'L': //halfling enemy
			return new HalflingEnemy(x,y);
			break;
		case 'M': //merchant
			return new Merchant(x,y);
			break;
		case 'D': //dragon enemy
			return new DragonEnemy(x,y);
			break;
	}
	return nullptr;
}
