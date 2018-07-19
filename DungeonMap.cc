#include "DungeonMap.h"
#include "Floor.h"
#include "Entity.h"
#include "TestEntity.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

DungeonMap::DungeonMap(const char *filename) {
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
		// cout << input;

		if (!endFloor) {
			++x;

			switch (input) {
			case '\n':
				if (startFloor) {
					startFloor = false;
					width = x;
					cout << "Starting Floor: " << width << endl;
				}
				x = -1;
				++y;
			break;
			case '|':
				// TODO add the wall object
	
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

					startFloor = true;
					endFloor = true;
					hitSomething = false;
					width = 0;
					x = -1;
					y = 0;
					cout << "Ending Floor" << endl;
				}
	
				// Continuing avoids setting hitSomething below this switch statement
				continue;
			case '-': // top wall
				es.emplace_back(new TestEntity(x, y, input));
				break;
			case '\\': // stairs
				break;
			case '.': // empty floor tile
				break;
			case '0': // restore health
				break;
			case '1': // boost attack
				break;
			case '2': // boost defense
				break;
			case '3': // poison health
				break;
			case '4': // wound attack
				break;
			case '5': // wound defense
				break;
			case '6': // normal gold pile
				break;
			case '7': // small hoard
				break;
			case '8': // merchant hoard
				break;
			case '9': // dragon hoard
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

