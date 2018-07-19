#include "DungeonMap.h"
#include "Entity.h"
#include <string>
#include <vector>

using namespace std;

DungeonMap::DungeonMap(string filename) {
	ifstream file(filename.c_str());
	if (!file) {
		cerr << "Error reading file: " << filename << endl;
		return;
	}

	this->grid = new vector<vector<Entity&>>

	char input;
	while (file >> input) {
		cout << input << endl;
	}
}

