#include "DungeonMap.h"
#include "Floor.h"
#include "Entity.h"
#include "Pathway.h"
#include "Wall.h"
#include "Ground.h"
#include "Potion.h"
#include "Gold.h"
#include "DragonGold.h"
#include "Stair.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

DungeonMap::DungeonMap(const char *filename, Character *player): player{player} {
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
				es.emplace_back(new Stair(x, y));
				break;
			case '.': // ground tile
				es.emplace_back(new Ground(x, y));
				break;
			case '@': // player
				es.emplace_back(player);
				player->setX(x);
				player->setY(y);
				break;
			case '0': // restore health
				es.emplace_back(new Potion(x, y, "Restore Health", nullptr));
				break;
			case '1': // boost attack
				es.emplace_back(new Potion(x, y, "Boost Attack", nullptr));
				break;
			case '2': // boost defense
				es.emplace_back(new Potion(x, y, "Boost Defences", nullptr));
				break;
			case '3': // poison health
				es.emplace_back(new Potion(x, y, "Poison Health", nullptr));
				break;
			case '4': // wound attack
				es.emplace_back(new Potion(x, y, "Wound Attack", nullptr));
				break;
			case '5': // wound defense
				es.emplace_back(new Potion(x, y, "Wound Defense", nullptr));
				break;
			case '6': // normal gold pile
				es.emplace_back(new Gold(x, y, 2));
				break;
			case '7': // small hoard
				es.emplace_back(new Gold(x, y, 1));
				break;
			case '8': // merchant hoard
				es.emplace_back(new Gold(x, y, 4));
				break;
			case '9': // dragon hoard
				es.emplace_back(new DragonGold(x, y));
				break;
			}
			// Checks if, when scanning across, we hit a non-wall character
			hitSomething = input == '-' ? hitSomething : true;
		} else { endFloor = false; }
	}
}

size_t DungeonMap::getFloor() { return floor; }

void DungeonMap::progressFloor() {
	// TODO Clean up current floor
	++floor;
	// TODO load new floor
}

ostream &operator<<(ostream &out, const DungeonMap &m) {
	return out << *m.floors[m.floor];
}

void DungeonMap::notify(Observer &other) {
	(void) other; // prevent unused parameter error, remove this later
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

void DungeonMap::movePlayer(Direction d) {
	for (Direction valid: getWalkableDirections(player)) {
		if (d == valid) {
			cout << "valid direction " << d.x << " " << d.y << endl;
			int x = player->getX();
			int y = player->getY();
			cout << "current player: " << x << " " << y << endl;
			vector<Entity *> row = floors[floor]->get(x, y);
			if (row.back() != player) { cerr << "wtf, player coordinates != map coordinates" << endl; }
			row.pop_back();
			player->move(d);
			floors[floor]->get(player->getX(), player->getY()).emplace_back(player);
			cout << "after move: " << player->getX() << " " << player->getY() << endl;
			break;
		}
	}
}