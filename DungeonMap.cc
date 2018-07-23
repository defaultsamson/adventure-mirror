#include "DungeonMap.h"
#include "Floor.h"
#include "Entity.h"
#include "Pathway.h"
#include "Wall.h"
#include "Ground.h"
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

CharacterDecorator *DungeonMap::getPlayer() { return player; }

DungeonMap::DungeonMap(const char *filename, CharacterDecorator *player, bool re): player{player} {
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
	vector<Entity *> es;

	size_t x = -1, y = 0;	// x and y coordinates of the current character

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
				es.emplace_back(new Wall(x, y, input));
	
				// At the left wall
				if (x == 0) {
					hitSomething = false;
				}
				// At the right wall (for the startingRead, width - 1 = -1), so this will never run on startingRead
				// If it made it without hitting anything and this isn't the starting line, then end the read of this floor
				else if (x == width - 1 && !hitSomething) {

					// Creates and initializes the floor
					Floor *fl = new Floor(width, y + 1);
					for (Entity *e: es) fl->add(e);
					es.clear();
					this->floors.emplace_back(fl);

					// Resets the floor variables
					startFloor = true;
					endFloor = true;
					hitSomething = false;
					width = 0;
					x = -1;
					y = 0;
				}
	
				// Continuing avoids setting hitSomething below this switch statement
				continue;
			case '#': // Pathway
			case '+':
				es.emplace_back(new Pathway(x, y, input));
				break;
			case '-': // top wall
				es.emplace_back(new Wall(x, y, input));
				break;
			case '\\': // stairs
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new Stair(x, y));
				break;
			case '.': // ground tile
				es.emplace_back(new Ground(x, y));
				break;
			case '@': // player
				es.emplace_back(new Ground(x, y));
				if (!re) {
					es.emplace_back(player);
					player->setX(x);
					player->setY(y);
				}
				break;
			case '0': // restore health
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new HealthPotion(x, y, "Restore Health", 5));
				break;
			case '1': // boost attack
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new EffectPotion(x, y, "Boost Attack", new BoostAtkEffect()));
				break;
			case '2': // boost defense
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new EffectPotion(x, y, "Boost Defences", new BoostDefEffect()));
				break;
			case '3': // poison health
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new HealthPotion(x, y, "Poison Health", -5));
				break;
			case '4': // wound attack
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new EffectPotion(x, y, "Wound Attack", new WoundAtkEffect()));
				break;
			case '5': // wound defense
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new EffectPotion(x, y, "Wound Defense", new WoundDefEffect()));
				break;
			case '6': // normal gold pile
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new Gold(x, y, 2));
				break;
			case '7': // small hoard
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new Gold(x, y, 1));
				break;
			case '8': // merchant hoard
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new Gold(x, y, 4));
				break;
			case '9': // dragon hoard
				es.emplace_back(new Ground(x, y));
				if (!re) es.emplace_back(new DragonGold(x, y));
				break;
			case 'H': //human enemy
				es.emplace_back(new Ground(x,y));
				if (!re) es.emplace_back(new HumanEnemy(x,y));
				break;
			case 'W': //dwarf enemy
				es.emplace_back(new Ground(x,y));
				if (!re) es.emplace_back(new DwarfEnemy(x,y));
				break;
			case 'E': //elf enemy
				es.emplace_back(new Ground(x,y));
				if (!re) es.emplace_back(new ElfEnemy(x,y));
				break;
			case 'O': //orc enemy
				es.emplace_back(new Ground(x,y));
				if (!re) es.emplace_back(new OrcEnemy(x,y));
				break;
			case 'L': //halfling enemy
				es.emplace_back(new Ground(x,y));
				if (!re) es.emplace_back(new HalflingEnemy(x,y));
				break;
			case 'M': //merchant
				es.emplace_back(new Ground(x,y));
				if (!re) es.emplace_back(new Merchant(x,y));
				break;
			case 'D': //dragon enemy
				es.emplace_back(new Ground(x,y));
				if (!re) es.emplace_back(new DragonEnemy(x,y));
				break;
			}
			// Checks if, when scanning across, we hit a non-wall character
			hitSomething = input == '-' ? hitSomething : true;
		} else { endFloor = false; }
	}
	//Spawn random item and enemies if the boolean re is true
	if (re){
		//We spawn random enemies and random potions for each of the floors
		for (size_t f = 0; f < floor + 1; f++){
			Floor *currentFloor = floors[f];
			//create a 2d vector to keep track of nodes we visited
			//Everything in the array is initialised to false, by default
			vector<vector<bool>> visited;
			for (size_t x = 0; x < currentFloor->height(); ++x){
				vector<bool> visitedRow;
				for (size_t y = 0; y < currentFloor->width(); ++y){
					visitedRow.emplace_back(false);
				}
				visited.emplace_back(visitedRow);
			}
			int chambersCount = 0;
			vector<Chamber> chambers;
			for (size_t x = 0; x < currentFloor->height(); ++x){
				for (size_t y = 0; y < currentFloor->width(); ++y){
					//We add tiles into chambers
					if (!visited[x][y]){
						visited[x][y] = true;
						vector<Entity*> e = currentFloor->get(y, x);
						if(e.size() && e.back()->isSpawnable()){
							//create a new chamber
							Chamber newChamber = Chamber();
							//The while loop performs a depth first search
							//for all connected floor tiles
							vector<Entity*> floorTiles;
							floorTiles.emplace_back(e.back());
							while(!floorTiles.empty()){
								//spawnableTiles is the current piles we are processing
								//floorTiles are tiles we will search at the next loop
								//move everything in floorTiles into spawnableTiles
								vector<Entity*> spawnableTiles = floorTiles;
								floorTiles.clear();
								for (auto it : spawnableTiles){
									//Add all nearby, unchecked floors to the spawnableTiles vector
									Entity* entity = it;
									vector<Direction> directions = getSpawnableDirections(entity);
									for (auto dit : directions){
										int connectedX = entity->getX() + dit.x;
										int connectedY = entity->getY() + dit.y;
										vector<Entity*> connectedTile = currentFloor->get(connectedY, connectedX);
										if (!visited[connectedX][connectedY]){
											visited[connectedX][connectedY] = true;
											floorTiles.emplace_back(connectedTile.back());
										}
									}
									newChamber.add(entity->getX(), entity->getY());
								}
							}
							chambers.emplace_back(newChamber);
							++chambersCount;
						}
					}
				}
			}
			//Now we add everything into chambers
			populate(currentFloor, chambers, chambersCount, player);
			chambers.clear();
			chambersCount = 0;
		}
	}
}

void DungeonMap::populate(Floor *fl, vector<Chamber> chambers, int cc, Character* player){
	for (auto it : chambers){
		it.shuffle();
	}
	//Spawn the treasures
	for (int i = 0; i < 10; ++i){
		//remove any full (empty for the vector) chambers
        	for (int j = cc - 1; j < 0; ++i){
                	if (chambers[j].isEmpty()){
				chambers.erase(chambers.begin() + j);
				--cc;
			}
        	}
		//roll a d8 to spawn treasures
		//0-4 is normal, 5-6 is small hoard, 7 is dragon hoard
		int roll = rand() % 8;
		//generate a random number to decide which chamber to spawn the item
		int chamberRoll = rand() % cc;
		if (roll < 5){
			fl->add(chambers[chamberRoll].spawnObject('6'));
		} else if (roll < 7){
			fl->add(chambers[chamberRoll].spawnObject('7'));
		} else {
			//Only spawn dragon hoard at a location if we can fit a dragon
			//next to it
			Entity* g = chambers[chamberRoll].spawnObject('8');
			vector<Direction> directions = getSpawnableDirections(g);
			while (directions.empty()){
				if (chambers[chamberRoll].isEmpty()){
					chambers.erase(chambers.begin() + chamberRoll);
					--cc;
					chamberRoll = rand() % cc;
				} else {
					delete g;
					g = chambers[chamberRoll].spawnObject('8');
					directions = getSpawnableDirections(g);
				}
                        }
			//spawn a dragon
			int directionCount = directions.size();
			int directionRoll = rand() % directionCount;
			Direction dir = directions[directionRoll];
			size_t dragonX = g->getX() + dir.x;
			size_t dragonY = g->getY() + dir.y;
			fl->add(new DragonEnemy(dragonX, dragonY));
			chambers[chamberRoll].remove(dragonX, dragonY);
		}
	}
	//Spawn the enemies
	for (int i = 0; i < 20; ++i){
                //remove any full (empty for the vector) chambers
                for (int j = cc - 1; j < 0; ++i){
                        if (chambers[j].isEmpty()){
                                chambers.erase(chambers.begin() + j);
                                --cc;
                        }
                }
                //roll a d18 to spawn enemies
                //0-4 is halfling, 5-8 is human, 9-11 is dwarf, 12-13 is elf, 14-15 is orc, 16-17 is merchant
                int roll = rand() % 18;
                //generate a random number to decide which chamber to spawn the entity
                int chamberRoll = rand() % cc;
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
	for (int i = 0; i < 10; ++i){
                //remove any full (empty for the vector) chambers
                for (int j = cc - 1; j < 0; ++i){
                        if (chambers[j].isEmpty()){
                                chambers.erase(chambers.begin() + j);
                                --cc;
                        }
                }
                //roll a d6 to spawn enemies
                int roll = rand() % 6;
                //generate a random number to decide which chamber to spawn the entity
                int chamberRoll = rand() % cc;
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
	for (int j = cc - 1; j < 0; ++j){
		if (chambers[j].isEmpty()){
			chambers.erase(chambers.begin() + j);
			--cc;
		}
	}
	//Spawn the exit
	int exitChamberRoll = rand() % cc;
	fl->add(chambers[exitChamberRoll].spawnObject('\\'));
	//Spawn the player
	chambers.erase(chambers.begin() + exitChamberRoll);
	--cc;
	int playerChamberRoll = rand() % cc;
	//We use a second stair to represent the player's spawn, but this stair
	//will not be added to the map.
	//It make sense to use a stair, since you walked up a stair after all
	Entity* spawn = chambers[playerChamberRoll].spawnObject('\\');
	player->setX(spawn->getX());
	player->setY(spawn->getY());
	fl->add(player);
}

size_t DungeonMap::getFloor() { return floor; }

void DungeonMap::progressFloor() {
	// TODO Clean up current floor
	++floor;
	// TODO load new floor
}

ostream &operator<<(ostream &out, const DungeonMap &m) {
	out << *m.floors[m.floor];
	out << "Race: " << m.player->getType().to_string() << " Gold: " << m.player->getGold() << " Floor: " << m.floor << endl;
	out << "HP: " << m.player->getHP() << "/" << (m.player->getMaxHP() > 0 ? to_string((int) m.player->getMaxHP()) : "Infinite") << endl;
	out << "Atk: " << m.player->getAtk() << endl;
	out << "Def: " << m.player->getDef();
	return out;
}

vector<Direction> DungeonMap::getWalkableDirections(Entity* e) {
	int x = e->getX();
	int y = e->getY();
	int width = floors[floor]->width();
	int height = floors[floor]->height();
	vector<Direction> valid;
	for (int col = x > 0 ? x - 1 : 0; col <= x + 1 && col < width; ++col) {
		for (int row = y > 0 ? y - 1 : 0; row <= y + 1 && row < height; ++row) {
			vector<Entity*> e = floors[floor]->get(col, row);
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

vector<Direction> DungeonMap::getSpawnableDirections(Entity* e) {
	int x = e->getX();
	int y = e->getY();
	int width = floors[floor]->width();
	int height = floors[floor]->height();
	vector<Direction> valid;
	for (int col = x > 0 ? x - 1 : 0; col <= x + 1 && col < width; ++col) {
		for (int row = y > 0 ? y - 1 : 0; row <= y + 1 && row < height; ++row) {
			vector<Entity*> e = floors[floor]->get(col, row);
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

void DungeonMap::move(Entity *e, Direction d) {
	int x = e->getX();
	int y = e->getY();
	vector<Entity *> &cell = floors[floor]->get(x, y);
	if (cell.back() == e) {
		cell.pop_back();
	}
	else {
		cerr << "wtf, player coordinates != map coordinates" << endl;
	}
	e->move(d);
	floors[floor]->add(e);
}

void DungeonMap::potionPlayer(Direction d, string &output) {
	size_t x = player->getX() + d.x;
	size_t y = player->getY() + d.y;
	vector<Entity*> &tile = floors[floor]->get(x, y);
	if (tile.size() > 0) {
		Potion *pot = dynamic_cast<Potion*>(tile.back());
		if (pot) {
			pot->pickup(player);
			tile.pop_back();
			// TODO output
			(void) output;
		}
	}
}

void DungeonMap::movePlayer(Direction d, string &output) {
	output = "";
	for (Direction valid: getWalkableDirections(player)) {
		if (d == valid) {
			move(player, d);
			output = "Action: PC moves " + d.to_string() + ". ";
			player->tick(*this, output);
			// make the second part optional, e.g when seeing a potion, we would say "and sees an unknown potion"
			return;
		}
	}
	output = "Action: PC attempts to move " + d.to_string() + ", but is blocked from moving that way.";
}

void DungeonMap::tick(string &output) {
	Floor *currentFloor = floors[floor];
	// TODO: if frozen, skip this loop
	for (size_t row = 0; row < currentFloor->height(); ++row) {
		for (size_t col = 0; col < currentFloor->width(); ++col) {
			vector<Entity *> cell = currentFloor->get(col, row);
			for (Entity * e: cell) {
				// enemies decide whether to move or not
				if (e != player) {
					e->moveTick(*this, output);
				}
			}
		}
	}
	for (size_t row = 0; row < currentFloor->height(); ++row) {
		for (size_t col = 0; col < currentFloor->width(); ++col) {
			vector<Entity *> cell = currentFloor->get(col, row);
			for (Entity * e: cell) {
				// if not moving, enemies will attack
				if (e != player) {
					e->tick(*this, output);
				}
			}
		}
	}
	for (size_t row = 0; row < currentFloor->height(); ++row) {
		for (size_t col = 0; col < currentFloor->width(); ++col) {
			vector<Entity *> cell = currentFloor->get(col, row);
			for (Entity * e: cell) {
				CharacterDecorator *c = dynamic_cast<CharacterDecorator *>(e);
				if (c) {
					c->resetTick();
				}
			}
		}
	}
}
