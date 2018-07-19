#include <string>
#include <iostream>

#include "DungeonMap.h"

using namespace std;

int main(int argc, char *argv[]) {
    /* Initially, the game will demand the player enter one of the specifed races or quit. Entering `q' or EOF (e.g.
    Ctrl-D) at the race prompt will cause the program to terminate. Supplying a valid race selection (below)
    will start that game using that race. Other values will be ignored.
    Play will continue in the specified way until the player restarts, reaches the end of floor 5, the PC dies,
    or the player quits. If the player reaches the end of the game or their character is slain, the game should
    give them the option of playing again or quitting.

    The following commands can be supplied to your command interpreter:
    * no,so,ea,we,ne,nw,se,sw: moves the player character one block in the appropriate cardinal direction.
    * u <direction>: uses the potion indicated by the direction (e.g. no, so, ea).
    * a <direction>: attacks the enemy in the specified direction, if the monster is in the immediately
    specified block (e.g. must be one block north of the @).
    * s, d, v, g, t: specifies the race the player wishes to be when starting a game.
    * f: stops enemies from moving until this key is pressed again.
    * r: restarts the game. All stats, inventory, and gold are reset. A new race should be selected.
    * q: allows the player to admit defeat and exit the game.
    Note that the board should be redrawn as appropriate every time a command is entered.*/

    string input;
    bool quit = false;

    while (!quit && cin >> input) {
        // race is one of (s, d, v, g, t)
        // if (input is one of above)
            // CharacterDecorator &race = get race deco from input

            // Character &player = BaseCharacter(set up character from race);

            const char *defaultMap = {"cc3kfloor.txt"};
            DungeonMap map{defaultMap};
            if (argc > 1) {
                map = DungeonMap(argv[1]);
            }
            cout << map << endl;

            // init map, enemies, items, etc here
            while (cin >> input) {
                // main game loop
                if (input == "q") {
                    cout << "Thank you for playing CC3K!" << endl;
                    quit = true;
                    break;
                }
                else if (input == "u") {
                    // yeah we might want to make a helper function to get direction
                    // Direction d;
                    // cin >> d;
                    // player.use(d);
                }
                else if (input == "a") {
                    // Direction d;
                    // cin >> d;
                    // player.attack(d);
                }
                else if (input == "f") {
                    // toggles stopping enemies from moving
                    // map.toggleStopEnemies()
                }
                else if (input == "r") {
                    cout << "Restarting Game" << endl;
                    // make sure we manage memory of previous player and stuff
                    break;
                }
                // instead of the following shit, maybe do
                // else {
                    // Direction d = getDirection(input);
                    // if (d != Direction::invalid) {
                        // player.move(d);
                    // }
                // }
                else if (input == "no") {
                    //player.move(north)
                }
                else if (input == "so") {
                    //player.move(south);
                }
                else if (input == "ea") {
                    //player.move(east);
                }
                else if (input == "we") {
                    //player.move(west);
                }
                else if (input == "ne") {
                    //player.move(northeast);
                }
                // etc., fuck this
            }
    }
}
