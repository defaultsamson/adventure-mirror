#ifndef DIRECTION_H_
#define DIRECTION_H_
#include <string>

struct Direction {
    int x, y;
    Direction(int x=0, int y=0, int x2=0, int y2=0); // handles direction from (x, y) and direction between two pairs
    std::string to_string();
    bool operator==(Direction other);
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
#endif
