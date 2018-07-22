#include "Direction.h"

Direction::Direction(int x, int y, int x2, int y2): x{x - x2}, y{y - y2} {}

bool Direction::operator==(Direction other) {
    return other.x == x && other.y == y;
}

const Direction Direction::N {0,-1};
const Direction Direction::NE {1, -1};
const Direction Direction::E{1, 0};
const Direction Direction::SE{1, 1};
const Direction Direction::S{0, 1};
const Direction Direction::SW{-1, 1};
const Direction Direction::W{-1, 0};
const Direction Direction::NW{-1, -1};
const Direction Direction::Invalid{0, 0};

Direction Direction::getDirection(std::string d) {
    if (d == "no") {
        return Direction::N;
    }
    else if (d == "so") {
        return Direction::S;
    }
    else if (d == "ea") {
        return Direction::E;
    }
    else if (d == "we") {
        return Direction::W;
    }
    else if (d == "ne") {
        return Direction::NE;
    }
    else if (d == "nw") {
        return Direction::NW;
    }
    else if (d == "se") {
        return Direction::SE;
    }
    else if (d == "sw") {
        return Direction::SW;
    }
    else {
        return Direction::Invalid;
    }
}
