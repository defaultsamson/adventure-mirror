#include <string>

struct Direction {
    int x, y;
    Direction(int x=0, int y=0);
    static Direction getDirection(std::string d);
    const static Direction N;
    const static Direction NE;
    const static Direction E;
    const static Direction SE;
    const static Direction S;
    const static Direction SW;
    const static Direction W;
    const static Direction NW;
    const static Direction Invalid;
};
