#include "DungeonMap.h"
#include "Entity.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

DungeonMap::DungeonMap(char *filename) {
	ifstream file{filename};
	if (!file) {
		cerr << "Error reading file: " << filename << endl;
		return;
	}
	
	char input;
	while (file >> input) {
		cout << input << endl;

		switch (input) {
		case '|':
			break;
		case '-':
			break;
		case '\\':
			break;
		case '.':
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
	}
}

void DungeonMap::notify(Observer &other) {

}

