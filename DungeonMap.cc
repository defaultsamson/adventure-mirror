#include "DungeonMap.h"
#include "Floor.h"
#include "Entity.h"
#include "Pathway.h"
#include "Wall.h"
#include "Ground.h"
#include "Potion.h"
#include "PotionType.h"
#include "HealthPotion.h"
#include "EffectPotion.h"
#include "BoostAtkEffect.h"
#include "BoostDefEffect.h"
#include "WoundAtkEffect.h"
#include "WoundDefEffect.h"
#include "Gold.h"
#include "DragonGold.h"
#include "Stair.h"
#include "CharacterDecorator.h"
#include "HumanEnemy.h"
#include "ElfEnemy.h"
#include "DwarfEnemy.h"
#include "OrcEnemy.h"
#include "HalflingEnemy.h"
#include "Merchant.h"
#include "DragonEnemy.h"
#include "Chamber.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

shared_ptr<CharacterDecorator> DungeonMap::getPlayer() { return player;}

void DungeonMap::witnessPotion(PotionType type) { potions.emplace_back(type); }
bool DungeonMap::seenPotion(PotionType type) {
	for (PotionType pt: potions) if (type == pt) return true;
	return false;
}

DungeonMap::DungeonMap(const char *filename, shared_ptr<CharacterDecorator> player, bool re): player{player} {
	// re = generate random entities
	for (int i = 0; i < (int) MapFlags::LAST; ++i) {
		flags.emplace_back(false);
	}
	ifstream file{filename};
	if (!file) {
		cerr << "Error reading file: " << filename << endl;
		return;
	}

	// These are used to determine the beginning and ending of the level
	bool startFloor = true;
	bool endFloor = false;
	bool hitSomething = false;
	size_t width = 0;	// Width of the level (including level box)

	// A stack of entities to add to the floor
	vector<shared_ptr<Entity>> es;

	size_t i = 0;
	size_t x = -1, y = 0, spawnX = 0, spawnY = 0;	// x and y coordinates of the current character

	char input;
	while (file.get(input)) {
		// cout << input; // Prints the file as it is read

		// At the end of the floor there should be a newline character. This will skip it
		if (!endFloor) {
			++x; // x starts at -1, so therefore this makes it start at 0, and increments it

			switch (input) {
			case '\n':
				if (startFloor) {
					// Ended the first line of the floor, we now know the width of it
					startFloor = false;
					width = x;
				}
				x = -1;
				++y;
			break;
			case '|':
				{
					shared_ptr<Entity> ent (new Wall(x, y, input));
					es.emplace_back(ent);
				}

				// At the left wall
				if (x == 0) {
					hitSomething = false;
				}
				// At the right wall (for the startingRead, width - 1 = -1), so this will never run on startingRead
				// If it made it without hitting anything and this isn't the starting line, then end the read of this floor
				else if (x == width - 1 && !hitSomething) {

					// Creates and initializes the floor
					shared_ptr<Floor> fl (new Floor(i, width, y + 1));
					for (shared_ptr<Entity> e: es) fl->add(e);
					es.clear();
					fl->setSpawn(spawnX, spawnY);
					this->floors.emplace_back(fl);

					// Resets the floor variables
					startFloor = true;
					endFloor = true;
					hitSomething = false;
					width = 0;
					x = -1;
					y = 0;
					++i;
				}
				// Continuing avoids setting hitSomething below this switch statement
				continue;
			case '#': // Pathway
			case '+':
				{
					shared_ptr<Entity> ent (new Pathway(x, y, input));
					es.emplace_back(ent);
				}
				break;
			case '-': // top wall
				{
					shared_ptr<Entity> ent (new Wall(x, y, input));
					es.emplace_back(ent);
				}
				break;
			case '\\': // stairs
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new Stair(x, y));
						es.emplace_back(ent);
					}
				}
				break;
			case '.': // ground tile
				{
					shared_ptr<Entity> ground (new Ground(x,y));
                                	es.emplace_back(ground);
				}break;
			case '@': // player
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					spawnX = x;
					spawnY = y;
				}
				break;
			case '0': // restore health
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new HealthPotion(x, y, PotionType::Health, 10));
						es.emplace_back(ent);
					}
				}
				break;
			case '1': // boost attack
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new EffectPotion(x, y, PotionType::BoostAttack, shared_ptr<CharacterDecorator>(new BoostAtkEffect())));
						es.emplace_back(ent);
					}
				}
				break;
			case '2': // boost defense
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new EffectPotion(x, y, PotionType::BoostDefense, shared_ptr<CharacterDecorator>(new BoostDefEffect())));
						es.emplace_back(ent);
					}
				}
				break;
			case '3': // poison health
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new HealthPotion(x, y, PotionType::Poison, -10));
						es.emplace_back(ent);
					}
				}
				break;
			case '4': // wound attack
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new EffectPotion(x, y, PotionType::WoundAttack, shared_ptr<CharacterDecorator>(new WoundAtkEffect())));
						es.emplace_back(ent);
					}
				}
				break;
			case '5': // wound defense
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new EffectPotion(x, y, PotionType::WoundDefense, shared_ptr<CharacterDecorator>(new WoundDefEffect())));
						es.emplace_back(ent);
					}
				}
				break;
			case '6': // normal gold pile
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new Gold(x, y, 2));
						es.emplace_back(ent);
					}
				}
				break;
			case '7': // small hoard
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new Gold(x, y, 1));
						es.emplace_back(ent);
					}
				}
				break;
			case '8': // merchant hoard
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new Gold(x, y, 4));
						es.emplace_back(ent);
					}
				}
				break;
			case '9': // dragon hoard
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new DragonGold(x, y));
						es.emplace_back(ent);
					}
				}
				break;
			case 'H': //human enemy
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new HumanEnemy(x, y));
						es.emplace_back(ent);
					}
				}
				break;
			case 'W': //dwarf enemy
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new DwarfEnemy(x, y));
						es.emplace_back(ent);
					}
				}
				break;
			case 'E': //elf enemy
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new ElfEnemy(x, y));
						es.emplace_back(ent);
					}
				}
				break;
			case 'O': //orc enemy
				{
					shared_ptr<Entity> ground (new Ground(x, y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new OrcEnemy(x, y));
						es.emplace_back(ent);
					}
				}
				break;
			case 'L': //halfling enemy
				{
					shared_ptr<Entity> ground (new Ground(x, y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new HalflingEnemy(x, y));
						es.emplace_back(ent);
					}
				}
				break;
			case 'M': //merchant
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new Merchant(x,y));
						es.emplace_back(ent);
					}
				}
				break;
			case 'D': //dragon enemy
				{
					shared_ptr<Entity> ground (new Ground(x,y));
					es.emplace_back(ground);
					if (!re) {
						shared_ptr<Entity> ent (new DragonEnemy(x,y));
						es.emplace_back(ent);
					}
				}
				break;
			}
			// Checks if, when scanning across, we hit a non-wall character
			hitSomething = input == '-' ? hitSomething : true;
		} else { endFloor = false; }
	}
	//Spawn random item and enemies if the boolean re is true
	if (re){
		//We spawn random enemies and random potions for each of the floors
		for (size_t f = 0; f < floors.size(); f++){
			//create a 2d vector to keep track of nodes we visited
			//Everything in the array is initialised to false, by default
			vector<vector<bool>> visited;
			for (size_t x = 0; x < floors[f]->width(); ++x){
				vector<bool> visitedCol;
				for (size_t y = 0; y < floors[f]->height(); ++y){
					visitedCol.emplace_back(false);
				}
				visited.emplace_back(visitedCol);
			}
			vector<Chamber> chambers;
			for (size_t x = 0; x < floors[f]->width(); ++x){
				for (size_t y = 0; y < floors[f]->height(); ++y){
					//We add tiles into chambers
					if (!visited[x][y]){
						visited[x][y] = true;
						vector<shared_ptr<Entity>> e = floors[f]->get(x, y);
						if(e.size() && e.back()->isSpawnable()){
							//create a new chamber
							Chamber newChamber = Chamber();
							//The while loop performs a depth first search
							//for all connected floor tiles
							vector<shared_ptr<Entity>> floorTiles;
							floorTiles.emplace_back(e.back());
							while(!floorTiles.empty()){
								//spawnableTiles is the current piles we are processing
								//floorTiles are tiles we will search at the next loop
								//move everything in floorTiles into spawnableTiles
								vector<shared_ptr<Entity>> spawnableTiles = floorTiles;
								floorTiles.clear();
								for (auto it : spawnableTiles){
									//Add all nearby, unchecked floors to the spawnableTiles vector
									shared_ptr<Entity> entity = it;
									vector<Direction> directions = getSpawnableDirections(entity, f);
									for (auto dit : directions){
										int connectedX = entity->getX() + dit.x;
										int connectedY = entity->getY() + dit.y;
										vector<shared_ptr<Entity>> connectedTile = floors[f]->get(connectedX, connectedY);
										if (!visited[connectedX][connectedY]){
											visited[connectedX][connectedY] = true;
											floorTiles.emplace_back(connectedTile.back());
										}
									}
									newChamber.add(entity->getX(), entity->getY());
								}
							}
							chambers.emplace_back(newChamber);
						}
					}
				}
			}
			//Now we add everything into chambers
			populate(f, chambers);
			chambers.clear();
		}
	}

	// Loads the first floor after everything
	progressFloor(true);
}

void DungeonMap::populate(size_t f, vector<Chamber> chambers){
	const shared_ptr<Floor> &fl = floors[f];
	unsigned seed = (unsigned) (rand() % 100);
	cout << "Seed: " << seed << endl;
	std::default_random_engine eng = std::default_random_engine(seed);
	for (Chamber& it : chambers){
		it.shuffle(eng);
	}
	//Spawn the treasures
	for (size_t i = 0; i < 10; ++i){
		//remove any full (empty for the vector) chambers
        	for (size_t j = 0; j < chambers.size(); ++j){
                	if (chambers[j].isEmpty()){
				chambers.erase(chambers.begin() + j);
				--j;
			}
        	}
		//roll a d8 to spawn treasures
		//0-4 is normal, 5-6 is small hoard, 7 is dragon hoard
		int roll = rand() % 8;
		//generate a random number to decide which chamber to spawn the item
		int chamberRoll = rand() % chambers.size();
		if (roll < 5){
			fl->add(chambers[chamberRoll].spawnObject('6'));
		} else if (roll < 7){
			fl->add(chambers[chamberRoll].spawnObject('7'));
		} else {
			//Only spawn dragon hoard at a location if we can fit a dragon
			//next to it
			shared_ptr<Entity> g = chambers[chamberRoll].spawnObject('9');
			vector<Direction> directions = getSpawnableDirections(g, f);
			while (directions.empty()){
				if (chambers[chamberRoll].isEmpty()){
					chambers.erase(chambers.begin() + chamberRoll);
					chamberRoll = rand() % chambers.size();
					g = chambers[chamberRoll].spawnObject('9');
					directions = getSpawnableDirections(g, f);
				} else {
					g = chambers[chamberRoll].spawnObject('9');
					directions = getSpawnableDirections(g, f);
				}
			}
			//spawn a dragon
			fl->add(g);
			int directionCount = (int) directions.size();
			int directionRoll = rand() % directionCount;
			Direction dir = directions[directionRoll];
			size_t dragonX = g->getX() + dir.x;
			size_t dragonY = g->getY() + dir.y;
			fl->add(shared_ptr<Entity> (new DragonEnemy(dragonX, dragonY)));
			chambers[chamberRoll].remove(dragonX, dragonY);
		}
	}
	//Spawn the enemies
	for (size_t i = 0; i < 20; ++i){
                //remove any full (empty for the vector) chambers
                for (size_t j = 0; j < chambers.size(); ++j){
                        if (chambers[j].isEmpty()){
                                chambers.erase(chambers.begin() + j);
                                --j;
                        }
                }
                //roll a d18 to spawn enemies
                //0-4 is halfling, 5-8 is human, 9-11 is dwarf, 12-13 is elf, 14-15 is orc, 16-17 is merchant
                int roll = rand() % 18;
                //generate a random number to decide which chamber to spawn the entity
                int chamberRoll = rand() % chambers.size();

                if (roll < 5){
                        fl->add(chambers[chamberRoll].spawnObject('L'));
                } else if (roll < 9){
                        fl->add(chambers[chamberRoll].spawnObject('H'));
                } else if (roll < 12){
			fl->add(chambers[chamberRoll].spawnObject('W'));
		} else if (roll < 14){
			fl->add(chambers[chamberRoll].spawnObject('E'));
		} else if (roll < 16){
			fl->add(chambers[chamberRoll].spawnObject('O'));
		} else {
			fl->add(chambers[chamberRoll].spawnObject('M'));
		}
	}
	//Spawn the potions
	for (size_t i = 0; i < 10; ++i){
                //remove any full (empty for the vector) chambers
                for (size_t j = 0; j < chambers.size(); ++j){
                        if (chambers[j].isEmpty()){
                                chambers.erase(chambers.begin() + j);
                                --j;
                        }
                }
                //roll a d6 to spawn enemies
                int roll = rand() % 6;
                //generate a random number to decide which chamber to spawn the entity
                int chamberRoll = rand() % chambers.size();
        	switch(roll){
			case 0 : fl->add(chambers[chamberRoll].spawnObject('0'));
				break;
			case 1 : fl->add(chambers[chamberRoll].spawnObject('1'));
				break;
			case 2 : fl->add(chambers[chamberRoll].spawnObject('2'));
				break;
			case 3 : fl->add(chambers[chamberRoll].spawnObject('3'));
				break;
			case 4 : fl->add(chambers[chamberRoll].spawnObject('4'));
				break;
			case 5 : fl->add(chambers[chamberRoll].spawnObject('5'));
				break;
		}
	}
	for (size_t j = 0; j < chambers.size(); ++j){
		if (chambers[j].isEmpty()){
			chambers.erase(chambers.begin() + j);
			--j;
		}
	}
	//Spawn the exit
	int exitChamberRoll = rand() % chambers.size();
	fl->add(chambers[exitChamberRoll].spawnObject('\\'));
	//Spawn the player
	chambers.erase(chambers.begin() + exitChamberRoll);
	int playerChamberRoll = rand() % chambers.size();
	//We use a second stair to represent the player's spawn, but this stair
	//will not be added to the map.
	//It make sense to use a stair, since you walked up a stair after all
	shared_ptr<Entity> spawn = chambers[playerChamberRoll].spawnObject('\\');
	fl->setSpawn(spawn->getX(), spawn->getY());
}

shared_ptr<Floor> &DungeonMap::getFloor() { return floors[floor]; }

bool DungeonMap::wonGame() { return won; }

void DungeonMap::progressFloor(bool start) {
	if (!start) {
		++floor;
	}

	if (floor >= floors.size()) {
		// END GAME
		won = true;
		floor = floors.size() - 1;
	} else {
		player->setX(getFloor()->spawnX());
		player->setY(getFloor()->spawnY());
		getFloor()->add(player);
	}
}

ostream &operator<<(ostream &out, const DungeonMap &m) {
	out << *m.floors[m.floor];
	out << "Race: " << m.player->getType().to_string() << " Gold: " << m.player->getGold() << " Floor: " << m.floor + 1 << endl;
	out << "HP: " << m.player->getHP() << "/" << (m.player->getMaxHP() > 0 ? to_string((int) m.player->getMaxHP()) : "Infinite") << endl;
	out << "Atk: " << m.player->getAtk() << endl;
	out << "Def: " << m.player->getDef();
	return out;
}

bool DungeonMap::getFlag(MapFlags f) {
	return flags[(int) f];
}

void DungeonMap::setFlag(MapFlags f, bool value) {
	flags[(int) f] = value;
}

void DungeonMap::toggleFlag(MapFlags f) {
	flags[(int) f] = !flags[(int) f];
}

//Called with the ptr 'this'
vector<Direction> DungeonMap::getWalkableDirections(Entity* e) {
	int x = e->getX();
	int y = e->getY();
	int width = floors[floor]->width();
	int height = floors[floor]->height();
	vector<Direction> valid;
	for (int col = x > 0 ? x - 1 : 0; col <= x + 1 && col < width; ++col) {
		for (int row = y > 0 ? y - 1 : 0; row <= y + 1 && row < height; ++row) {
			if (col == x && row == y) continue;
			vector<shared_ptr<Entity>> e = floors[floor]->get(col, row);
			if (e.size() && e.back()->isWalkable()) {
				valid.emplace_back(Direction(col, row, x, y));
			}
		}
	}
	if (!valid.size()) {
		// no valid directions
		valid.emplace_back(Direction::Invalid);
	}
	return valid;
}

//Called with smart pointer
vector<Direction> DungeonMap::getWalkableDirections(shared_ptr<Entity> e) {
	int x = e->getX();
	int y = e->getY();
	int width = floors[floor]->width();
	int height = floors[floor]->height();
	vector<Direction> valid;
	for (int col = x > 0 ? x - 1 : 0; col <= x + 1 && col < width; ++col) {
		for (int row = y > 0 ? y - 1 : 0; row <= y + 1 && row < height; ++row) {
			if (col == x && row == y) continue;
			vector<shared_ptr<Entity>> e = floors[floor]->get(col, row);
			if (e.size() && e.back()->isWalkable()) {
				valid.emplace_back(Direction(col, row, x, y));
			}
		}
	}
	if (!valid.size()) {
		// no valid directions
		valid.emplace_back(Direction::Invalid);
	}
	return valid;
}

//Called with the ptr 'this'
vector<Direction> DungeonMap::getSpawnableDirections(Entity* e) {
	int x = e->getX();
	int y = e->getY();
	int width = floors[floor]->width();
	int height = floors[floor]->height();
	vector<Direction> valid;
	for (int col = x > 0 ? x - 1 : 0; col <= x + 1 && col < width; ++col) {
		for (int row = y > 0 ? y - 1 : 0; row <= y + 1 && row < height; ++row) {
			if (col == x && row == y) continue;
			vector<shared_ptr<Entity>> e = floors[floor]->get(col, row);
			if (e.size() && e.back()->isSpawnable()) {
				valid.emplace_back(Direction(col, row, x, y));
			}
		}
	}
	if (!valid.size()) {
		// no valid directions
		valid.emplace_back(Direction::Invalid);
	}
	return valid;
}

//Called with smart pointer
vector<Direction> DungeonMap::getSpawnableDirections(shared_ptr<Entity> e) {
	int x = e->getX();
	int y = e->getY();
	int width = floors[floor]->width();
	int height = floors[floor]->height();
	vector<Direction> valid;
	for (int col = x > 0 ? x - 1 : 0; col <= x + 1 && col < width; ++col) {
		for (int row = y > 0 ? y - 1 : 0; row <= y + 1 && row < height; ++row) {
			if (col == x && row == y) continue;
			vector<shared_ptr<Entity>> e = floors[floor]->get(col, row);
			if (e.size() && e.back()->isSpawnable()) {
				valid.emplace_back(Direction(col, row, x, y));
			}
		}
	}
	if (!valid.size()) {
		// no valid directions
		valid.emplace_back(Direction::Invalid);
	}
	return valid;
}

vector<Direction> DungeonMap::getSpawnableDirections(shared_ptr<Entity> e, size_t fl) {
        int x = e->getX();
        int y = e->getY();
        int width = floors[fl]->width();
        int height = floors[fl]->height();
        vector<Direction> valid;
        for (int col = x > 0 ? x - 1 : 0; col <= x + 1 && col < width; ++col) {
                for (int row = y > 0 ? y - 1 : 0; row <= y + 1 && row < height; ++row) {
                        if (col == x && row == y) continue;
                        vector<shared_ptr<Entity>> e = floors[fl]->get(col, row);
                        if (e.size() && e.back()->isSpawnable()) {
                                valid.emplace_back(Direction(col, row, x, y));
                        }
                }
        }
        if (!valid.size()) {
                // no valid directions
                valid.emplace_back(Direction::Invalid);
        }
        return valid;
}

void DungeonMap::move(shared_ptr<Entity>e, Direction d) {
	int x = e->getX();
	int y = e->getY();
	vector<shared_ptr<Entity>> &cell = floors[floor]->get(x, y);
	if (cell.back() == e) {
		cell.pop_back();
	}
	else {
		cerr << "wtf, coordinates != map coordinates" << endl;
	}
	e->move(d);
	floors[floor]->add(e);
}

void DungeonMap::playerPotion(Direction d, string &output) {
	size_t x = player->getX() + d.x;
	size_t y = player->getY() + d.y;
	vector<shared_ptr<Entity>> &tile = floors[floor]->get(x, y);
	if (tile.size() > 0) {
		shared_ptr<Potion> pot = dynamic_pointer_cast<Potion>(tile.back());
		if (pot) {
			output += "PC uses ";
			if (pot->pickup(*this, *player, output)) {
				tile.pop_back();
				player->tick(*this, output);
			}
			return;
		}
	}
	output += "PC attempts to drink the air, but fails";
}

bool DungeonMap::playerMove(Direction d, string &output) {
	output = "Action: ";
	for (Direction valid: getWalkableDirections(player)) {
		if (d == valid) {
			move(player, d);
			output += "PC moves " + d.to_string();
			// string additionalOutput;
			// and sees a furry friend. Use additionalOutput for output.
			/*player->tick(*this, additionalOutput);
			if (!additionalOutput.empty()) {
				output += " " + additionalOutput;
			}*/
			player->tick(*this, output);
			size_t x = player->getX(), y = player->getY();
			vector<shared_ptr<Entity>> &tile = floors[floor]->get(x, y);
			double prevGold = player->getGold();
			for (size_t i = 0; i < tile.size(); ++i) {
				shared_ptr<Item> item = dynamic_pointer_cast<Item>(tile[i]);
				if (item) {
					if (item->pickup(*this, *player, output)) {
						tile.erase(tile.begin() + i);
						--i;
					}
					continue;
				}
				shared_ptr<Stair> stair = dynamic_pointer_cast<Stair>(tile[i]);
				if (stair) {
					// If there's a stair in this tile, progress the floor
					progressFloor();
					output += " and exits from floor " + to_string(floor) + ". ";
					return false;
				}
			}

			if (player->getGold() != prevGold) {
				output += " and picks up " + to_string((int)(player->getGold() - prevGold)) + " treasure";
			}
			output += ". ";

			bool didSees = false;
			for (size_t i = x - 1; i < x + 2; ++i) {
				for (size_t j = y - 1; j < y + 2; ++j) {
					if (i == x && j == y) continue; // Skip the player tile
					shared_ptr<Entity> e = floors[floor]->getTop(i, j);
					shared_ptr<Character> c = dynamic_pointer_cast<Character>(e);
					if (c) {
						output += (didSees ? " and a " : "PC sees a ") + c->getType().to_string();
						didSees = true;
						continue;
					}
					shared_ptr<Potion> p = dynamic_pointer_cast<Potion>(e);
					if (p) {
						output += (didSees ? " and " : "PC sees ");
						if (seenPotion(p->getType())) {
							output += "a " + p->getType().to_string();
						} else {
							output += "an Unknown Potion";
						}
						didSees = true;
						continue;
					}
					if (dynamic_pointer_cast<DragonGold>(e)) {
						output += (didSees ? " and a " : "PC sees a ");
						output += "dragon hoard";
						didSees = true;
						continue;
					}
					if (dynamic_pointer_cast<Gold>(e)) {
						output += (didSees ? " and a " : "PC sees a ");
						output += "some treasure";	
						didSees = true;
						continue;
					}
				}
			}
			if (didSees) output += ". ";
			return true;
		}
	}
	output = "PC attempts to move " + d.to_string() + ", but is blocked from moving that way. ";
	return true;
}

void DungeonMap::playerAttack(Direction d, string &output) {
	output = "Action: ";
	size_t x = player->getX() + d.x;
	size_t y = player->getY() + d.y;
	vector<shared_ptr<Entity>> &tile = floors[floor]->get(x, y);
	if (tile.size() > 0) {
		shared_ptr<Enemy> e = dynamic_pointer_cast<Enemy>(tile.back());
		if (e) {
			player->hit(*e, output);
			if (e->deathCheck()) {
				output += "PC slays the " + e->getType().to_string();
				e->onDeath(*this, output);
				// TODO: delete e; or use smart pointers
				tile.pop_back();
				output += "! ";
			}
			else {
				output += "(" + to_string((int) e->getHP()) + " HP). ";
			}
			shared_ptr<Merchant> m = dynamic_pointer_cast<Merchant>(e);
			if (m) {
				if (!getFlag(MapFlags::MerchantsHostile)) {
					output += "PC has enraged the merchants! Merchants will attack PC from now on. ";
				}
				setFlag(MapFlags::MerchantsHostile, true);
			}
		}
		else {
			output += "PC attacks the ground unsuccessfully. ";
		}
	}
}

void DungeonMap::tick(string &output) {
	const shared_ptr<Floor> &currentFloor = floors[floor];
	if (!flags[(int)MapFlags::EnemiesFrozen]) {
		for (size_t row = 0; row < currentFloor->height(); ++row) {
			for (size_t col = 0; col < currentFloor->width(); ++col) {
				vector<shared_ptr<Entity>> cell = currentFloor->get(col, row);
				for (shared_ptr<Entity> e: cell) {
					// enemies decide whether to move or not
					if (e != player && !passTick) {
						e->moveTick(*this, output);
					}
				}
			}
		}
	}
	for (size_t row = 0; row < currentFloor->height(); ++row) {
		for (size_t col = 0; col < currentFloor->width(); ++col) {
			vector<shared_ptr<Entity>> cell = currentFloor->get(col, row);
			for (shared_ptr<Entity> e: cell) {
				// if not moving, enemies will attack
				if (e != player && !passTick) {
					e->tick(*this, output);
				}
			}
		}
	}
	for (size_t row = 0; row < currentFloor->height(); ++row) {
		for (size_t col = 0; col < currentFloor->width(); ++col) {
			vector<shared_ptr<Entity>> cell = currentFloor->get(col, row);
			for (shared_ptr<Entity> e: cell) {
				shared_ptr<CharacterDecorator> c = dynamic_pointer_cast<CharacterDecorator>(e);
				if (c && !passTick) {
					c->resetTick();
				}
			}
		}
	}
	passTick = false;
}

string DungeonMap::validate() {
	const shared_ptr<Floor>& currentFloor = floors[floor];
	string output = "~~~~Map Validation~~~~";
	for (size_t row = 0; row < currentFloor->height(); ++row) {
		for (size_t col = 0; col < currentFloor->width(); ++col) {
			vector<shared_ptr<Entity>> cell = currentFloor->get(col, row);
			for (shared_ptr<Entity> e: cell) {
				if (e->getX() != col || e->getY() != row) {
					output += "\nEntity " + to_string(e->print()) + " has internal (" + to_string(e->getX()) + ", " + to_string(e->getY()) + ")";
					output += " but map (" + to_string(col) + ", " + to_string(row) + ")";
				}
			}
		}
	}
	return output;
}

string DungeonMap::characterStats() {
	const shared_ptr<Floor>& currentFloor = floors[floor];
	string output = "~~~~Character Stats~~~~";
	for (size_t row = 0; row < currentFloor->height(); ++row) {
		for (size_t col = 0; col < currentFloor->width(); ++col) {
			vector<shared_ptr<Entity>> cell = currentFloor->get(col, row);
			for (shared_ptr<Entity> e: cell) {
				shared_ptr<Character> c = dynamic_pointer_cast<Character>(e);
				if (c) {
					output += "\n" + c->to_string();
				}
			}
		}
	}
	return output;
}

string DungeonMap::itemStats() {
	const shared_ptr<Floor>& currentFloor = floors[floor];
	string output = "~~~~Item Stats~~~~";
	for (size_t row = 0; row < currentFloor->height(); ++row) {
		for (size_t col = 0; col < currentFloor->width(); ++col) {
			vector<shared_ptr<Entity>> cell = currentFloor->get(col, row);
			for (shared_ptr<Entity> e: cell) {
				shared_ptr<Gold> gold = dynamic_pointer_cast<Gold>(e);
				if (gold) {
					output += "\nGold $" + to_string(gold->getValue()) + "(" + to_string(col) + ", " + to_string(row) + ")";
				}
				else {
					shared_ptr<Potion> potion = dynamic_pointer_cast<Potion>(e);
					if (potion) {
						output += "\n" + potion->getType().to_string() + "(" + to_string(col) + ", " + to_string(row) + ")";
						// output += "\n" + potion->to_string(); // why isn't this working
					}
				}
			}
		}
	}
	return output;
}
